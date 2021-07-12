require 'sinatra'

set :bind, '0.0.0.0'
set :port, 8080

helpers do
  def protected!
    return if authorized?
    headers['WWW-Authenticate'] = 'Basic realm="Restricted Area"'
    halt 401, "401 Not authorized\n"
  end

  def authorized?
    @auth ||=  Rack::Auth::Basic::Request.new(request.env)
    @auth.provided? and @auth.basic? and @auth.credentials and @auth.credentials == ['admin', 'admin']
  end
end

get '/' do
    ["Alice Blue Gown", "All the Way Home", "American Beauty Rose", "And Then You Kissed Me", "Anything", "April in Paris", "Around the World", "At Least a Little in Love", "Autumn Leaves", "Ave Maria", "A Baby Just Like You", "Bali Ha'i", "Barbara", "Black", "Body and Soul", "Buds Won't Bud", "California", "Can I Steal a Little Love?", "The Charm of You", "The Christmas Waltz"].sample()
end

get '/birth_date' do
    "December 12, 1915"
end

get '/birth_city' do
    "Hoboken, New Jersey"
end

get '/wives' do
    "Nancy Barbato, Ava Gardner, Mia Farrow, Barbara Marx"
end

get '/picture' do
    redirect 'https://upload.wikimedia.org/wikipedia/commons/a/af/Frank_Sinatra_%2757.jpg'
end

get '/public' do
    "Everybody can see this page"
end

get '/protected' do
    protected!
    "Welcome, authenticated client"
end

