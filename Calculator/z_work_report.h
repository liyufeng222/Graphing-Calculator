#ifndef Z_WORK_REPORT_H
#define Z_WORK_REPORT_H

/*
    Features:
        -Not Implemented:
              none
        -Implemented:
              This graphing calculator, can draw any function that input from
              the sfml interface, press f the input the function in the box
              it will draw the function. User can pan the graph up down right
              and left using the arrow key. Zoom in and zoom out the graph,
              uses shift+enter or enter, also can use mouse wheel and touch
              bar.It has a help screen, when user press h. Function input
              will save in the sidebar, and user can click on the functions
              in the sidebar to swith the graph. Press R for return to default
              domain info. F2 will save the function in the history list in
              the sidebar, it will save to the txt file, and next time open
              up the program, will show on the sidebar.
        -Partly implemented: None
              none
    Bugs     :
              features that are implemented are bug-free.

    Reflections:
        The relationship between classes is very important, graph_info
        class is go throught the whole project, by changing the graph_info
        pointer object, it will change the graphing calculator. Once update
        new stuff, need to send command from animate to system to change info.
        However, It is a very challenging program.
*/

#endif // Z_WORK_REPORT_H
