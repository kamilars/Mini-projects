var app = require('express')();
const basicAuth = require('express-basic-auth');

/*app.use(basicAuth({
    users: {
        'admin': 'admin',
    }
}))
*/

var auth = basicAuth(function(user, pass, next) {
    var result = (user === 'admin' && pass === 'admin');
    next(null, result);
});


app.get('/', function(req, res) {
    var songs = ["Alice Blue Gown", "All the Way Home", "American Beauty Rose", "And Then You Kissed Me", "Anything", "April in Paris", "Around the World", "At Least a Little in Love", "Autumn Leaves", "Ave Maria", "A Baby Just Like You", "Bali Ha'i", "Barbara", "Black", "Body and Soul", "Buds Won't Bud", "California", "Can I Steal a Little Love?", "The Charm of You", "The Christmas Waltz"]; 
    res.send(songs[Math.floor(Math.random() * songs.length)]);
});

app.get("/birth_date", function(req, res){
    res.send("December 12, 1915");
});

app.get("/birth_city", function(req, res){
    res.send("Hoboken, New Jersey");
});

app.get("/wives", function(req, res){
    res.send("Nancy Barbato, Ava Gardner, Mia Farrow, Barbara Marx");
});

app.get("/picture", function(req, res){
    res.redirect('https://upload.wikimedia.org/wikipedia/commons/a/af/Frank_Sinatra_%2757.jpg');
});

app.get("/public", function(req, res){
    res.send("Everybody can see this page");
});

app.get("/protected", auth, function(req, res){
    res.send("Welcome, authenticated client");
});

app.listen(8080, '0.0.0.0');