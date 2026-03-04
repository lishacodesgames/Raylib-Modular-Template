#pragma once
// NEVER include Precompiled headers in header files. 
// Only in cpp, at the very top of everything else.

class Game {
public:
   void Init();
   void Run();

private: // members
   int x = 400;
   int y = 300;
private: // methods
   void HandleEvents();
   void Draw();
};