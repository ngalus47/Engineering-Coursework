BeginDrawing():
            ClearBackground(BLUE);
            DrawCircle(75, 75, 10,             buttons & 8 ? BLUE : DARKBLUE);
            DrawCircle(250 - 75, 75, 10,       buttons & 1 ? BLUE : DARKBLUE);
            DrawCircle(75, 250 - 75, 10,       buttons & 4 ? YELLOW : DARKYELLOW);
            DrawCircle(250 - 75, 250 - 75, 10, buttons & 2 ? YELLOW : DARKYELLOW);
EndDrawing();