void Menu_f(int Menu)
{
    menu_music = Mix_LoadMUS("menu.wav");
    Mix_PlayMusic(menu_music, 0);

    Menu=1;
    while (Menu)
    {
        SDL_Event event;
        SDL_Surface* tela = SDL_GetWindowSurface(main_window);
        SDL_SetRenderDrawColor(main_renderer, 0, 0, 0, 255);
        SDL_BlitSurface(menu,NULL, tela,NULL);

        SDL_UpdateWindowSurface(main_window);
        SDL_Delay(100);

        while( SDL_PollEvent( &event ) )
        {
            switch(event.type)
            {

                case SDL_QUIT: //Exit();
                               break;

                case SDL_MOUSEBUTTONDOWN: if(event.button.button == SDL_BUTTON_LEFT || event.button.button == SDL_BUTTON_RIGHT)
                                          {
                                            if((event.button.x >= 360 && event.button.y >=306) && (event.button.x <=454 && event.button.y<= 322)) /*START*/
                                            {
                                                //Start();
                                            }
                                            else if((event.button.x >= 371 && event.button.y >=450) && (event.button.x <=444 && event.button.y<=467)) /* HELP */
                                            {
                                                //Help();
                                            }
                                            else if((event.button.x >= 376 && event.button.y >=483) && (event.button.x <=438 && event.button.y<=500)) /*Options*/
                                            {
                                                //Exit();
                                            }
                                            else if((event.button.x >= 348 && event.button.y >=409) && (event.button.x <=468 && event.button.y<=426)) // RANK
                                            {
                                                //Rank();
                                            }
                                          }
                                          break;
            }
        }
    }
}



