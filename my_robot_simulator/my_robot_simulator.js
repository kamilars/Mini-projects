function my_robot_simulator(instr){
    x = 0;
    y = 0;
    face = "north";

    for (i = 0; i < instr.length; i++){
        if (instr[i] == 'L') {
            switch (face) {
                case "north":
                    face = "west";
                    break;
                case "west":
                    face = "south";
                    break;
                case "south":
                    face = "east";
                    break;
                case "east":
                    face = "north";
                    break;
            }
        }
        else if (instr[i] == 'R') {
            switch (face) {
                case "north":
                    face = "east";
                    break;
                case "west":
                    face = "north";
                    break;
                case "south":
                    face = "west";
                    break;
                case "east":
                    face = "south";
                    break;
            }
        }
        else if (instr[i] == 'A'){
            switch (face) {
                case "north":
                    y--;
                    break;
                case "west":
                    x--;
                    break;
                case "south":
                    y++;
                    break;
                case "east":
                    x++;
                    break;
            }
        }
    }

    return "{x: " + x +", y: " + y +", bearing: '" + face +"'}";
}