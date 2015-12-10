# Let's redo this merkle tree to be a genserver

defmodule MerkleTree do
  use Genserver

  # PUBLIC API

  def start_link(leaves) do
    GenServer.start_link(__MODULE__, %{leaves: leaves, root: merkle(leaves)})
  end

  # PRIVATE API

  def handle_call(:get_root, _from, %{leaves: leaves, root: root} = payload) do
    {:reply, root, payload}
  end

  def handle_call({:diff, from_root}, _from, %{leaves: leaves, root: root} = payload) do
    {:reply, from_root != root, payload}
  end

  defp merkle([root]) do
    root
  end

  defp merkle(leaves) do
    IO.puts "LEVEL -----------------"
    IO.inspect(length(leaves))
    merkle(leaves |> Stream.chunk(2, 2, []) |> Stream.map(&hash(&1)) |> Enum.to_list)
  end

  defp hash([a, b]) do
    # Due to big-endian / little endian, we reverse the children
    # and then reverse the output.
    a1 = a |> Base.decode16!(case: :lower) |> String.reverse
    b1 = b |> Base.decode16!(case: :lower) |> String.reverse

    c = :crypto.hash(:sha256, a1 <> b1)

    # Double-hashed SHA256
    # https://en.bitcoin.it/wiki/Protocol_documentation#Merkle_Trees
    c1 = :crypto.hash(:sha256, c) |> String.reverse |> Base.encode16(case: :lower)
    IO.inspect(c1)
    c1
  end

  # For the cases where we have an odd number of leaves,
  # when we run into a group of one leaf (at the end)
  # we will need to hash the last item twice.
  defp hash([a]) do
    hash([a, a])
  end
end

