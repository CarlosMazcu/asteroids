



void InitFondo()
{
    figures = (TFigureInter*)malloc(n_figures * sizeof(TFigureInter));
    white = esat::SpriteFromFile("./Resources/blanco.png");
    logo = esat::SpriteFromFile("./Resources/Asteroids-Logo1.png");
    for(int i = 0; i < n_figures; i++){
        (figures + i)->pos.x = rand()%800;
        (figures + i)->pos.y = rand() % 600;
        (figures + i)->gravity = (rand()%5) + 2;
        (figures + i)->size = rand()%3 + 1;
        (figures + i)->star = esat::SubSprite(white, 0,0,(figures + i)->size,(figures + i)->size);
    }
}

void CleanUpStars()
{

    for(int i = 0; i < n_figures; i++){
        esat::SpriteRelease((figures + i)->star);
    }
    free(figures);
    (figures) = nullptr;
}

void DrawFondo()
{

    for (int i = 0; i < n_figures; i++)
    {
        esat::DrawSprite((figures + i)->star,(figures + i)->pos.x,(figures + i)->pos.y);
    }
    esat::DrawSprite(logo, 235, 70);
}

void MoveFondo()
{
    // Gravity
    for (int i = 0; i < n_figures; i++)
    {
        (figures + i)->pos.y += (figures + i)->gravity;
    }
    for (int i = 0; i < n_figures; i++)
    {
        if ((figures + i)->pos.y >= 600)
        {
            (figures + i)->pos.y = 0 - (figures + i)->size ;
        }
        if ((figures + i)->pos.x <= 0 - (figures + i)->size )
        {
            (figures + i)->pos.x = 800;
        }
        else if ((figures + i)->pos.x >= 800)
        {
            (figures + i)->pos.x = 0;
        }
    }
}

void Fondo(){
    MoveFondo();
    DrawFondo();
}

