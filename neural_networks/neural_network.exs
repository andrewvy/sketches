defmodule NeuralNet do
  defstruct input_layer_size: 2,
    output_layer_size: 1,
    hidden_layer_size: 3,
    weight_1: 0,
    weight_2: 0
end

defmodule NeuralNetwork do
  use GenServer

  def start_link do
    GenServer.start_link(__MODULE__, [NeuralNet%{}, []])
  end

  def sigmoid do
  end

  def forward(neural_net, x) do
    updated_neural_net = %{ neural_net | }
  end
end

x = [
  [0.3, 1],
  [0.5, 0.2],
  [1, 0.4]
]

y = [
  [0.75],
  [0.82],
  [0.93]
]
