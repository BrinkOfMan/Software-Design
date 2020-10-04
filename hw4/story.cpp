#include"../print.h"

int main(){
    print("\nYou wake up from sleep, not knowing what time it is.\n");
    print("It's dark. Your body still yearns for sleep, but it also might be morning.\n");
    print("What should you do?\n1: Go back to sleep.\n2: Wake up.\nPlease choose an option:\n");
    int first = input_int();

    if(first == 1){
        print("\nYou wake up again, but now it's light. You see that your 9 AM software design class starts soon.\n");
        print("You could do two things right now:\n");
        print("1: Quickly sprint over to class.\n2: Freshen up a bit before going to class.\nPlease choose an option:\n");
        int second = input_int();
        if(second==1)
            print("\nYou make it to class on time, but look quite disheveled.\nThere was a quiz today, good thing you made it on time.\nEven though you started out with some lingering adrenaline, the test wasn't too hard.\n[END]\n");
        else
            print("\nYou look and feel good, but forgot that there was a test today.\nBecause you showed up late, you were unable to finish the test.\nYou fail so terribly that you ended the course 1 point away from a passing grade.\nThere's always next semester!\n[END]\n");
    }
    else{
        print("\nDespite feeling groggy, you get up, get clean, and get dressed.\n");
        print("The shower helped you wake up.\nBut now you are hungry.\n");
        print("You remember that there's a test in software design today, and could use the extra time before class to study.\nWhat will you do?\n");
        print("1: Go to breakfast\n2: Study before class\n");
        int second = input_int();
        if(second==1)
            print("\nBreakfast was refreshing, and you even snuck in a little review of memory diagrams to boost confidence.\nThe test goes fine, and the rest of your day plays out normally.\n[END]\n");
        else
            print("\nYou take the extra time to study, eventually forgetting that you are hungry.\nYou get the top score in the class and bump up your overall grade with this test.\n[END]\n");
    }
    

}