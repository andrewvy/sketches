require 'virtus'
require 'celluloid'

class KV
  include Virtus.model

  attribute :store, Hash[String => String], :default => {}
  attribute :key_count, Integer, :default => 0
end

class KVStore
  include Celluloid

  def initialize()
    @kv = KV.new
  end
  def set(key, value)
    @kv.store[key] = value
  end

  def get(key)
    @kv.store[key]
  end

  def count()
    @kv.key_count
  end
end

kv = KVStore.new
future = kv.future.set("Hello", "World!")
puts kv.get("Hello")
