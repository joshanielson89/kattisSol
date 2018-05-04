#include <iostream>
#include <vector>

int main(){
    std::vector<std::vector<int>> moveVec;
    for(int i = 0; i < 4; i++){
        int a,b,c,d;
        std::cin >> a >> b >> c >> d;
        moveVec.push_back({a,b,c,d});
    }
    int dir;
    std::cin >> dir;
    // zero means left swipe
    if(dir == 0){
        std::vector<std::vector<int>> answerVec = {{},{},{},{}};
        for(int i = 0; i < 4; i++){
            bool noZero = true;
            if(moveVec[i][0] == 0 && moveVec[i][1] == 0 && moveVec[i][2] == 0 && moveVec[i][3] == 0) noZero = false;
            //first one
            if(moveVec[i][0] == moveVec[i][1]) {
                moveVec[i][0] *= 2;
                moveVec[i][1] = 0;
            }else if(moveVec[i][1] == 0 && moveVec[i][0] == moveVec[i][2]){
                moveVec[i][0] *= 2;
                moveVec[i][2] = 0;
            }else if(moveVec[i][1] == 0 && moveVec[i][2] == 0 && moveVec[i][0] == moveVec[i][3]){
                moveVec[i][0] *=2;
                moveVec[i][3] = 0;
            }
            //second one
            if(moveVec[i][1] == moveVec[i][2]){
                moveVec[i][1] *= 2;
                moveVec[i][2] = 0;
            }else if(moveVec[i][2] ==0 && moveVec[i][1] == moveVec[i][3]){
                moveVec[i][1] *= 2;
                moveVec[i][3] = 0;
            }
            // third one
            if(moveVec[i][2] == moveVec[i][3]){
                moveVec[i][2] *= 2;
                moveVec[i][3] = 0;
            }
            // shifts
            while(moveVec[i][0] == 0 && noZero){
                moveVec[i][0] = moveVec[i][1];
                moveVec[i][1] = moveVec[i][2];
                moveVec[i][2] = moveVec[i][3];
                moveVec[i][3] = 0;
                std::vector<int> zeroVec = {0,0,0,0};
                if(moveVec[i] == zeroVec) break;
            }
            while(moveVec[i][1] == 0 && noZero){
                moveVec[i][1] = moveVec[i][2];
                moveVec[i][2] = moveVec[i][3];
                moveVec[i][3] = 0;
                if(moveVec[i][1] == 0 && moveVec[i][2] == 0 && moveVec[i][3] == 0) break;
            }
            while(moveVec[i][2] == 0 && noZero){
                moveVec[i][2] = moveVec[i][3];
                moveVec[i][3] = 0;
                if(moveVec[i][2] == 0 && moveVec[i][3] == 0) break;
            }
            answerVec[i].push_back(moveVec[i][0]);
            answerVec[i].push_back(moveVec[i][1]);
            answerVec[i].push_back(moveVec[i][2]);
            answerVec[i].push_back(moveVec[i][3]);
        }   
        for(size_t i = 0; i < answerVec.size(); i++){
            for(size_t j = 0; j < answerVec[i].size(); j++){
                std::cout << answerVec[i][j] << " ";
            }
            std::cout << std::endl;
        }   
    }
    // two means right swipe
    if(dir == 2){
        std::vector<std::vector<int>> answerVec = {{},{},{},{}};
        for(int i = 0; i < 4; i++){
            bool noZero = true;
            if(moveVec[i][0] == 0 && moveVec[i][1] == 0 && moveVec[i][2] == 0 && moveVec[i][3] == 0) noZero = false;
            //first one
            if(moveVec[i][3] == moveVec[i][2]) {
                moveVec[i][3] *= 2;
                moveVec[i][2] = 0;
            }else if(moveVec[i][2] == 0 && moveVec[i][3] == moveVec[i][1]){
                moveVec[i][3] *= 2;
                moveVec[i][1] = 0;
            }else if(moveVec[i][2] == 0 && moveVec[i][1] == 0 && moveVec[i][3] == moveVec[i][0]){
                moveVec[i][3] *=2;
                moveVec[i][0] = 0;
            }
            //second one
            if(moveVec[i][2] == moveVec[i][1]){
                moveVec[i][2] *= 2;
                moveVec[i][1] = 0;
            }else if(moveVec[i][1] ==0 && moveVec[i][2] == moveVec[i][0]){
                moveVec[i][2] *= 2;
                moveVec[i][0] = 0;
            }
            // third one
            if(moveVec[i][1] == moveVec[i][0]){
                moveVec[i][1] *= 2;
                moveVec[i][0] = 0;
            }
            // shifts
            while(moveVec[i][3] == 0 && noZero){
                moveVec[i][3] = moveVec[i][2];
                moveVec[i][2] = moveVec[i][1];
                moveVec[i][1] = moveVec[i][0];
                moveVec[i][0] = 0;
                std::vector<int> zeroVec = {0,0,0,0};
                if(moveVec[i] == zeroVec) break;
            }
            while(moveVec[i][2] == 0 && noZero){
                moveVec[i][2] = moveVec[i][1];
                moveVec[i][1] = moveVec[i][0];
                moveVec[i][0] = 0;
                if(moveVec[i][2] == 0 && moveVec[i][1] == 0 && moveVec[i][0] == 0) break;
            }
            while(moveVec[i][1] == 0 && noZero){
                moveVec[i][1] = moveVec[i][0];
                moveVec[i][0] = 0;
                if(moveVec[i][1] == 0 && moveVec[i][0] == 0) break;
            }
            answerVec[i].push_back(moveVec[i][0]);
            answerVec[i].push_back(moveVec[i][1]);
            answerVec[i].push_back(moveVec[i][2]);
            answerVec[i].push_back(moveVec[i][3]);
        }       
        for(size_t i = 0; i < answerVec.size(); i++){
            for(size_t j = 0; j < answerVec[i].size(); j++){
                std::cout << answerVec[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    // one means up swipe
    if(dir == 1){
        std::vector<std::vector<int>> answerVec = {{},{},{},{}};
        for(int i = 0; i < 4; i++){
            bool noZero = true;
            if(moveVec[0][i] == 0 && moveVec[1][i] == 0 && moveVec[2][i] == 0 && moveVec[3][i] == 0) noZero = false;
            //first one
            if(moveVec[0][i] == moveVec[1][i]) {
                moveVec[0][i] *= 2;
                moveVec[1][i] = 0;
            }else if(moveVec[1][i] == 0 && moveVec[0][i] == moveVec[2][i]){
                moveVec[0][i] *= 2;
                moveVec[2][i] = 0;
            }else if(moveVec[1][i] == 0 && moveVec[2][i] == 0 && moveVec[0][i] == moveVec[3][i]){
                moveVec[0][i] *=2;
                moveVec[3][i] = 0;
            }
            //second one
            if(moveVec[1][i] == moveVec[2][i]){
                moveVec[1][i] *= 2;
                moveVec[2][i] = 0;
            }else if(moveVec[2][i] ==0 && moveVec[1][i] == moveVec[3][i]){
                moveVec[1][i] *= 2;
                moveVec[3][i] = 0;
            }
            // third one
            if(moveVec[2][i] == moveVec[3][i]){
                moveVec[2][i] *= 2;
                moveVec[3][i] = 0;
            }
            // shifts
            while(moveVec[0][i] == 0 && noZero){
                moveVec[0][i] = moveVec[1][i];
                moveVec[1][i] = moveVec[2][i];
                moveVec[2][i] = moveVec[3][i];
                moveVec[3][i] = 0;
                if(moveVec[0][i] == 0 && moveVec[1][i] == 0 && moveVec[2][i] == 0 && moveVec[3][i] == 0) break;
            }
            while(moveVec[1][i] == 0 && noZero){
                moveVec[1][i] = moveVec[2][i];
                moveVec[2][i] = moveVec[3][i];
                moveVec[3][i] = 0;
                if(moveVec[1][i] == 0 && moveVec[2][i] == 0 && moveVec[3][i] == 0) break;
            }
            while(moveVec[2][i] == 0 && noZero){
                moveVec[2][i] = moveVec[3][i];
                moveVec[3][i] = 0;
                if(moveVec[2][i] == 0 && moveVec[3][i] == 0) break;
            }
            answerVec[0].push_back(moveVec[0][i]);
            answerVec[1].push_back(moveVec[1][i]);
            answerVec[2].push_back(moveVec[2][i]);
            answerVec[3].push_back(moveVec[3][i]);
        }       
        for(size_t i = 0; i < answerVec.size(); i++){
            for(size_t j = 0; j < answerVec[i].size(); j++){
                std::cout << answerVec[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    if(dir == 3){
        std::vector<std::vector<int>> answerVec = {{},{},{},{}};
        for(int i = 0; i < 4; i++){
            bool noZero = true;
            if(moveVec[3][i] == 0 && moveVec[2][i] == 0 && moveVec[1][i] == 0 && moveVec[0][i] == 0) noZero = false;
            //first one
            if(moveVec[3][i] == moveVec[2][i]) {
                moveVec[3][i] *= 2;
                moveVec[2][i] = 0;
            }else if(moveVec[2][i] == 0 && moveVec[3][i] == moveVec[1][i]){
                moveVec[3][i] *= 2;
                moveVec[1][i] = 0;
            }else if(moveVec[2][i] == 0 && moveVec[1][i] == 0 && moveVec[3][i] == moveVec[0][i]){
                moveVec[3][i] *=2;
                moveVec[0][i] = 0;
            }
            //second one
            if(moveVec[2][i] == moveVec[1][i]){
                moveVec[2][i] *= 2;
                moveVec[1][i] = 0;
            }else if(moveVec[1][i] == 0 && moveVec[2][i] == moveVec[0][i]){
                moveVec[2][i] *= 2;
                moveVec[0][i] = 0;
            }
            // third one
            if(moveVec[1][i] == moveVec[0][i]){
                moveVec[1][i] *= 2;
                moveVec[0][i] = 0;
            }
            // shifts
            while(moveVec[3][i] == 0 && noZero){
                moveVec[3][i] = moveVec[2][i];
                moveVec[2][i] = moveVec[1][i];
                moveVec[1][i] = moveVec[0][i];
                moveVec[0][i] = 0;
                if(moveVec[3][i] == 0 && moveVec[2][i] == 0 && moveVec[1][i] == 0 && moveVec[0][i] == 0) break;
            }
            while(moveVec[2][i] == 0 && noZero){
                moveVec[2][i] = moveVec[1][i];
                moveVec[1][i] = moveVec[0][i];
                moveVec[0][i] = 0;
                if(moveVec[2][i] == 0 && moveVec[1][i] == 0 && moveVec[0][i] == 0) break;
            }
            while(moveVec[1][i] == 0 && noZero){
                moveVec[1][i] = moveVec[0][i];
                moveVec[0][i] = 0;
                if(moveVec[1][i] == 0 && moveVec[0][i] == 0) break;
            }
            answerVec[0].push_back(moveVec[0][i]);
            answerVec[1].push_back(moveVec[1][i]);
            answerVec[2].push_back(moveVec[2][i]);
            answerVec[3].push_back(moveVec[3][i]);
        }       
        for(size_t i = 0; i < answerVec.size(); i++){
            for(size_t j = 0; j < answerVec[i].size(); j++){
                std::cout << answerVec[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}