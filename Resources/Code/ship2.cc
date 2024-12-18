void InitPlayer(){

    player = (TPlayer*)calloc(2, sizeof(TPlayer));

    for(int i = 0; i < n_players; i++){
        (player + i)->score = 0;
        (player + i)->score_text = nullptr;
        (player + i)->score_text = (char *)calloc(7, sizeof(char));
        (player + i)->n_score_to_up_live = 10000;
        if(multiplayer){
            if(hardcore){
                (player + i)->lives = 2;
            }else{
                (player + i)->lives = 3;
            }
        }else{
            if(hardcore){
                (player + 0)->lives = 2;
            }else{
                (player + 0)->lives = 3;
            }
        }
    }
    
    

    P1 = (char*)calloc(3, sizeof(char));
    P2 = (char*)calloc(3, sizeof(char));
    copyright = (char*)calloc(12, sizeof(char));


    //TODO hacer free de p1, p2 y de copy
    *(P1 + 0) = 'P';
    *(P1 + 1) = '1';
    *(P1 + 2) = '\0';

    *(P2 + 0) = 'P';
    *(P2 + 1) = '2';
    *(P2 + 2) = '\0';

    *(copyright + 0) = '1';
    *(copyright + 1) = '9';
    *(copyright + 2) = '7';
    *(copyright + 3) = '9';
    *(copyright + 4) = ' ';
    *(copyright + 5) = ' ';
    *(copyright + 6) = 'A';
    *(copyright + 7) = 'T';
    *(copyright + 8) = 'A';
    *(copyright + 9) = 'R';
    *(copyright + 10) = 'I';
    *(copyright + 11) = '\0';
}

void InitBaseShoot(){
    base_shoot.vertex = 4;
    base_shoot.points = (esat::Vec3*)malloc(base_shoot.vertex * sizeof(esat::Vec3));
    *(base_shoot.points + 0) = {1.0f, 1.0f, 1.0f};
    *(base_shoot.points + 1) = {-1.0f, 1.0f, 1.0f};
    *(base_shoot.points + 2) = {-1.0f, -1.0f, 1.0f};
    *(base_shoot.points + 3) = {1.0f, -1.0f, 1.0f};
}

void InitGameShoot(){
    shoots = (TEntities*)malloc(kShootPool * sizeof(TEntities));
    for(int i = 0; i < kShootPool - 1; i++){
        (shoots + i)->figure.vertex = 0;
        (shoots + i)->vel = {320.0f, 320.0f};
        (shoots + i)->rotate_vel = 1.0f;
        (shoots + i)->active = false;
        (shoots + i)->figure.color = {255, 255, 255, 0};
        (shoots + i)->figure.transform = {};
        (shoots + i)->respawn_timer = 0;
        (shoots + i)->figure.tr_points = (esat::Vec2 *)malloc(4 * sizeof(esat::Vec2));
        (shoots + i)->figure.points = nullptr;
    }
    (shoots + (kShootPool - 1))->figure.vertex = 0;
    (shoots + (kShootPool - 1))->vel = {150.0f, 150.0f};
    (shoots + (kShootPool - 1))->rotate_vel = 1.0f;
    (shoots + (kShootPool - 1))->active = false;
    (shoots + (kShootPool - 1))->figure.color = {255, 255, 255, 0};
    (shoots + (kShootPool - 1))->figure.transform = {};
    (shoots + (kShootPool - 1))->respawn_timer = 0;
    (shoots + (kShootPool - 1))->figure.tr_points = (esat::Vec2 *)malloc(4 * sizeof(esat::Vec2));
    (shoots + (kShootPool - 1))->figure.points = nullptr;
}

void InitBaseParticulas(){
    
    base_particulas = (TBaseFigures*)malloc(2 * sizeof(TBaseFigures));

    (base_particulas + 0)->vertex = 4;
    (base_particulas + 1)->vertex = 4;

    (base_particulas + 0)->points = (esat::Vec3*)malloc(4 * sizeof(esat::Vec3));
    (base_particulas + 1)->points = (esat::Vec3*)malloc(4 * sizeof(esat::Vec3));

    *((base_particulas + 0)->points + 0) = {0.707f,0.707f,1.0f};
    *((base_particulas + 0)->points + 1) = {-0.707f,0.707f,1.0f};
    *((base_particulas + 0)->points + 2) = {-0.707f,-0.707f,1.0f};
    *((base_particulas + 0)->points + 3) = {0.707f,-0.707f,1.0f};
    
    *((base_particulas + 1)->points + 0) = {10.0f, 1.0f, 1.0f};
    *((base_particulas + 1)->points + 1) = {-10.0f, 1.0f, 1.0f};
    *((base_particulas + 1)->points + 2) = {10.0f, -1.0f, 1.0f};
    *((base_particulas + 1)->points + 3) = {-10.0f, -1.0f, 1.0f};
}

void InitGameParticulas(){
    particulas = (TEntities*)malloc(kParticulasPool * sizeof(TEntities));
    for(int i = 0; i < kParticulasPool; i++){
        (particulas + i)->figure.vertex = 4;
        (particulas + i)->vel = {15.0f, 15.0f};
        (particulas + i)->rotate_vel = 0.0f;
        (particulas + i)->active = false;
        (particulas + i)->figure.color = {255, 255, 255, 0};
        (particulas + i)->figure.transform = {};
        (particulas + i)->figure.tr_points = (esat::Vec2*)malloc(4 * sizeof(esat::Vec2));
        (particulas + i)->figure.points = nullptr;
        (particulas + i)->respawn_timer = 0;

    }
}

void InitGameAsteroids(){
    game_asteroids = (TEntities*)malloc(kAsteroidPool * sizeof(TEntities));
    for(int i = 0; i < kAsteroidPool; i++){
        (game_asteroids + i)->figure.vertex = 0;
        (game_asteroids + i)->vel = {75.0f, 75.0f};
        (game_asteroids + i)->rotate_vel = 0.0f;
        (game_asteroids + i)->active = false;
        (game_asteroids + i)->figure.color = {255, 255, 255, 0};
        (game_asteroids + i)->figure.transform = {};
        (game_asteroids + i)->figure.tr_points = (esat::Vec2*)malloc(12 * sizeof(esat::Vec2));
        (game_asteroids + i)->figure.points = nullptr;
        (game_asteroids + i)->respawn_timer = 0;

    }
}

void InitBaseAsteroids(){
    base_asteroids = (TBaseFigures*)malloc(kNAsteroidsBase * sizeof(TBaseFigures));
    (base_asteroids + 0)->vertex = 12;
    (base_asteroids + 1)->vertex = 12;
    (base_asteroids + 2)->vertex = 10;
    (base_asteroids + 3)->vertex = 11;

    for(int i = 0; i < kNAsteroidsBase; i++){
        (base_asteroids + i)->points = (esat::Vec3*)malloc((base_asteroids + i)->vertex * sizeof(esat::Vec3));
    }

    *((base_asteroids + 0)->points + 0) = {-0.958f, -0.416f, 1.0f};
    *((base_asteroids + 0)->points + 1) = {-0.392f, -0.912f, 1.0f};
    *((base_asteroids + 0)->points + 2) = {0.040f, -0.816f, 1.0f};
    *((base_asteroids + 0)->points + 3) = {0.542f, -0.910f, 1.0f};
    *((base_asteroids + 0)->points + 4) = {0.946f, -0.344f, 1.0f};
    *((base_asteroids + 0)->points + 5) = {0.620f, -0.082f, 1.0f};
    *((base_asteroids + 0)->points + 6) = {0.858f, 0.404f, 1.0f};
    *((base_asteroids + 0)->points + 7) = {0.300f, 0.904f, 1.0f};
    *((base_asteroids + 0)->points + 8) = {-0.126f, 0.824f, 1.0f};
    *((base_asteroids + 0)->points + 9) = {-0.542f, 0.906f, 1.0f};
    *((base_asteroids + 0)->points + 10) = {-0.960f, 0.594f, 1.0f};
    *((base_asteroids + 0)->points + 11) = {-0.716f, 0.160f, 1.0f};

    *((base_asteroids + 1)->points + 0) = {-0.918, -0.342, 1.0f};
    *((base_asteroids + 1)->points + 1) = {-0.268, -0.352, 1.0f};
    *((base_asteroids + 1)->points + 2) = {-0.532, -0.704, 1.0f};
    *((base_asteroids + 1)->points + 3) = {0.120, -0.704, 1.0f};
    *((base_asteroids + 1)->points + 4) = {0.840, -0.340, 1.0f};
    *((base_asteroids + 1)->points + 5) = {0.836, -0.170, 1.0f};
    *((base_asteroids + 1)->points + 6) = {0.170, 0.000, 1.0f};
    *((base_asteroids + 1)->points + 7) = {0.852, 0.344, 1.0f};
    *((base_asteroids + 1)->points + 8) = {0.418, 0.702, 1.0f};
    *((base_asteroids + 1)->points + 9) = {0.170, 0.502, 1.0f};
    *((base_asteroids + 1)->points + 10) = {-0.520, 0.692, 1.0f};
    *((base_asteroids + 1)->points + 11) = {-0.906, 0.186, 1.0f};

    *((base_asteroids + 2)->points + 0) = {-0.892,-0.334,1.0f};
    *((base_asteroids + 2)->points + 1) = {-0.444,-0.684,1.0f};
    *((base_asteroids + 2)->points + 2) = {0.002,-0.304,1.0f};
    *((base_asteroids + 2)->points + 3) = {0.434,-0.714,1.0f};
    *((base_asteroids + 2)->points + 4) = {0.900,-0.310,1.0f};
    *((base_asteroids + 2)->points + 5) = {0.634,0.028,1.0f};
    *((base_asteroids + 2)->points + 6) = {0.866,0.424,1.0f};
    *((base_asteroids + 2)->points + 7) = {0.210,0.754,1.0f};
    *((base_asteroids + 2)->points + 8) = {-0.428,0.734,1.0f};
    *((base_asteroids + 2)->points + 9) = {-0.878,0.410,1.0f};

    *((base_asteroids + 3)->points + 0) = {1.0f/6.0f, -1.0f/6.0f, 1.0f};
    *((base_asteroids + 3)->points + 1) = {-1.0f / 6.0f, 5.0f / 6.0f, 1.0f};
    *((base_asteroids + 3)->points + 2) = {2.0f / 6.0f, 5.0f / 6.0f, 1.0f};
    *((base_asteroids + 3)->points + 3) = {5.0f / 6.0f, 0.0f, 1.0f};
    *((base_asteroids + 3)->points + 4) = {5.0f / 6.0f, -2.0f / 6.0f, 1.0f};
    *((base_asteroids + 3)->points + 5) = {1.0f / 6.0f, -6.0f / 6.0f, 1.0f};
    *((base_asteroids + 3)->points + 6) = {-1.0f / 6.0f, -6.0f / 6.0f, 1.0f};
    *((base_asteroids + 3)->points + 7) = {-4.0f / 6.0f, -1.0f / 6.0f, 1.0f};
    *((base_asteroids + 3)->points + 8) = {-2.0f / 6.0f, 0.0f, 1.0f};
    *((base_asteroids + 3)->points + 9) = {-4.0f / 6.0f, 1.0f / 6.0f, 1.0f};
    *((base_asteroids + 3)->points + 10) = {-2.0f / 6.0f, 4.0f / 6.0f, 1.0f};
}

void InitCircle(){
    //circunferencia animacion muerte
    circle = (esat::Vec2*)malloc(knVertexCircle * sizeof(esat::Vec2));
    d = (M_PI * 2)/knVertexCircle;
    for(int i = 0; i < knVertexCircle; i++){
        (circle + i)->x = sinf(d * i);
        (circle + i)->y = cosf(d * i);
    }
}

void InitFigures(){
    //SHIP
    ship.vel = {0.0f, 0.0f};
    ship.rotate_vel = 3.5f;
    ship.active = true;
    ship.dir = {};
    ship.inmortal = true;
    ship.inmortal_timer = 0.0f;
    ship.respawn_timer = 0.0f;

    ship.figure.vertex = 5;
    ship.figure.points = (esat::Vec3*)malloc(ship.figure.vertex * sizeof(esat::Vec3));
    ship.figure.tr_points = (esat::Vec2*)malloc(ship.figure.vertex * sizeof(esat::Vec2));
    
    *(ship.figure.points + 0) = {-0.206,-0.424,1.0f};
    *(ship.figure.points + 1) = {0.928,-0.004,1.0f};
    *(ship.figure.points + 2) = {-0.210,0.418,1.0f};
    *(ship.figure.points + 3) = {-0.064,0.144,1.0f};
    *(ship.figure.points + 4) = {-0.064,-0.142,1.0f};

    ship.figure.transform.scale = {20.0f, 20.0f};
    ship.figure.transform.origin = {0.0f, 0.0f};
    ship.figure.transform.origin_rotate = 0.0f;
    ship.figure.transform.rotate = -M_PI_2;
    ship.figure.transform.pos = {400.0f, 300.0f};

    ship.figure.color.r = 255;
    ship.figure.color.g = 255;
    ship.figure.color.b = 255;
    ship.figure.color.a = 0;


    /////OVNI INIT////
    ovni.vel.y = 2.5f;
    ovni.vel.x = rand()%2;
    if(ovni.vel.x == 0.0f){
        ovni.vel.x = -2.5f;
    }
    if(ovni.vel.x == 1.0f){
        ovni.vel.x = 2.5f;
    }
    ovni.rotate_vel = 0.0f;
    ovni.active = false;
    ovni.dir = {0.0f, 0.0f};
    ovni.respawn_timer = 0.0f;

    ovni.figure.vertex = 12;
    ovni.figure.points = (esat::Vec3 *)malloc(ovni.figure.vertex * sizeof(esat::Vec3));
    ovni.figure.tr_points = (esat::Vec2 *)malloc(ovni.figure.vertex * sizeof(esat::Vec2));

    *(ovni.figure.points + 0) = {-0.844f, 0.194f, 1.0f};
    *(ovni.figure.points + 1) = {-0.416f, 0.566f, 1.0f};
    *(ovni.figure.points + 2) = {0.268f, 0.580f, 1.0f};
    *(ovni.figure.points + 3) = {0.704f, 0.194f, 1.0f};
    *(ovni.figure.points + 4) = {-0.824f, 0.206f, 1.0f};
    *(ovni.figure.points + 5) = {-0.384f, -0.156f, 1.0f};
    *(ovni.figure.points + 6) = {0.310f, -0.174f, 1.0f};
    *(ovni.figure.points + 7) = {0.716f, 0.154f, 1.0f};
    *(ovni.figure.points + 8) = {0.302f, -0.184f, 1.0f};
    *(ovni.figure.points + 9) = {0.182f, -0.634f, 1.0f};
    *(ovni.figure.points + 10) = {-0.210f, -0.622f, 1.0f};
    *(ovni.figure.points + 11) = {-0.376f, -0.190f, 1.0f};

    ovni.figure.transform.scale = kBigOvni;
    ovni.figure.transform.origin = {0.0f, 0.0f};
    ovni.figure.transform.origin_rotate = 0.0f;
    ovni.figure.transform.rotate = 0.0f;
    ovni.figure.transform.pos = {-100.0f, (float)(rand()%kWindowHeight)};

    ovni.figure.color.r = 255;
    ovni.figure.color.g = 255;
    ovni.figure.color.b = 255;
    ovni.figure.color.a = 0;

    InitBaseAsteroids();
    InitGameAsteroids();

    InitCircle();
    
    InitBaseShoot();
    InitGameShoot();

    InitBaseParticulas();
    InitGameParticulas();
}

void InitEntities(){
    int offset = 0;
    global_entities = (TEntities**)malloc(kNEntities * sizeof(TEntities*));
    *(global_entities + offset) = &ship;
    offset++;

    *(global_entities + offset) = &ovni;
    offset++;
    
    for(int i = 0; i < kAsteroidPool; i++){
        *(global_entities + offset) = (game_asteroids + (i));
        offset++;
    }
    for (int i = 0; i < kShootPool; i++)
    {
        *(global_entities + offset) = (shoots + (i));
        offset++;
    }

    for (int i = 0; i < kParticulasPool; i++)
    {
        *(global_entities + offset) = (particulas + (i));
        offset++;
    }
}

TEntities *AvailableInPool(TEntities *pool, const int pool_size)
{
    if (nullptr == pool)
    {
        printf("pool nula \n");
        return nullptr;
    }
    TEntities *game_object = nullptr;
    int offset = 0;
    while (game_object == nullptr && offset < pool_size)
    {
        if ((pool + offset)->active == false)
        {
            game_object = (pool + offset);
        }
        offset++;
    }
    return game_object;
}

void SpawnAsteroids(TTransform tr){
    TEntities *aux_asteroid = AvailableInPool(game_asteroids, kAsteroidPool);
    if(aux_asteroid == nullptr){
        printf("nullptr\n");
        return;
    }
    aux_asteroid->figure.transform = tr;
    aux_asteroid->active = true;
    int offset = rand()%4;
    aux_asteroid->figure.points = (base_asteroids + offset)->points;
    aux_asteroid->figure.vertex = (base_asteroids + offset)->vertex;
    aux_asteroid->figure.transform.scale = kBigAsteroid;
}

void SpawnBullet(TTransform tr){
    TEntities *aux_bullet = AvailableInPool(shoots, kShootPool);
    if(aux_bullet == nullptr){
        return;
    }
    aux_bullet->figure.transform = tr;
    aux_bullet->active = true;
    aux_bullet->figure.points = base_shoot.points;
    aux_bullet->figure.vertex = base_shoot.vertex;
}

void SpawnOvniBullet(TTransform tr){
    if (counter_bullet_ovni >= 4.0f)
    {
        int offset = rand()%knVertexCircle;
        (shoots + (kShootPool - 1))->figure.transform = tr;
        (shoots + (kShootPool - 1))->active = true;
        (shoots + (kShootPool - 1))->figure.points = base_shoot.points;
        (shoots + (kShootPool - 1))->figure.vertex = base_shoot.vertex;
        (shoots + (kShootPool - 1))->dir = Vec2Normalize(SubVec2(ship.figure.transform.pos, tr.pos));
        (shoots + (kShootPool - 1))->figure.transform.rotate = atan2f((shoots + (kShootPool - 1))->dir.y,(shoots + (kShootPool - 1))->dir.x);
        (shoots + (kShootPool - 1))->vel = {320.0f, 320.0f};
        counter_bullet_ovni = 0;
        
    }
}

void TransformFunction(TFigure *figure){
    if (figure == nullptr)
    {
        return;
    }

    figure->transform.transform_matrix = esat::Mat3Identity();
    figure->transform.transform_matrix = esat::Mat3Multiply(esat::Mat3Scale(figure->transform.scale.x, figure->transform.scale.y), figure->transform.transform_matrix);

    figure->transform.transform_matrix = esat::Mat3Multiply(esat::Mat3Rotate(figure->transform.origin_rotate), figure->transform.transform_matrix);
    figure->transform.transform_matrix = esat::Mat3Multiply(esat::Mat3Translate(figure->transform.origin.x, figure->transform.origin.y), figure->transform.transform_matrix);

    figure->transform.transform_matrix = esat::Mat3Multiply(esat::Mat3Rotate(figure->transform.rotate), figure->transform.transform_matrix);
    figure->transform.transform_matrix = esat::Mat3Multiply(esat::Mat3Translate(figure->transform.pos.x, figure->transform.pos.y), figure->transform.transform_matrix);
    /* figure->transform.transform_matrix = esat::Mat3Multiply(esat::Mat3Translate(esat::MousePositionX(),esat::MousePositionY()), figure->transform.transform_matrix); */


    esat::Vec3 aux = {};
    for (int i = 0; i < figure->vertex; i++)
    {
        aux = esat::Mat3TransformVec3(figure->transform.transform_matrix, *(figure->points + i));
        (figure->tr_points + i)->x = aux.x;
        (figure->tr_points + i)->y = aux.y;
    }
}

void DrawFigure(TFigure figure){
    esat::DrawSetStrokeColor(figure.color.r, figure.color.g, figure.color.b);
    esat::DrawSetFillColor(figure.color.r, figure.color.g, figure.color.b, figure.color.a);
    esat::DrawSolidPath(&figure.tr_points->x, figure.vertex);
}

void HyperSpace(esat::Vec2 *position){
        position->x = rand()%800;
        position->y = rand()%600;
        ship.inmortal = true;
        bool_hyperspace = true;
}

void RotateFigure(TEntities *entitie)
{
    if (esat::IsSpecialKeyPressed(esat::kSpecialKey_Right))
    {

        entitie->figure.transform.rotate += entitie->rotate_vel * (float)delta;
    }
    if (esat::IsSpecialKeyPressed(esat::kSpecialKey_Left))
    {
        entitie->figure.transform.rotate -= entitie->rotate_vel * (float)delta;
    }
}

void MoveShip(TEntities *entitie){

    float max_speed = 3.5f;
    float deceleration = 0.97f;
    static esat::Vec2 inert = {0.0f, 0.0f};
    entitie->dir = {cosf(entitie->figure.transform.rotate), sinf(entitie->figure.transform.rotate)};
    inert.x = entitie->dir.x * 0.2;
    inert.y = entitie->dir.y * 0.2;
    entitie->figure.transform.pos.x += entitie->vel.x;
    entitie->figure.transform.pos.y += entitie->vel.y;
    if (esat::IsSpecialKeyPressed(esat::kSpecialKey_Up) && (entitie->vel.x < max_speed && entitie->vel.y < max_speed) &&
        (entitie->vel.x > max_speed * (-1) && entitie->vel.y > max_speed * (-1)))
    {
        entitie->vel.x += inert.x;
        entitie->vel.y += inert.y;
    }
    else
    {
        entitie->vel.x = entitie->vel.x * deceleration;
        entitie->vel.y = entitie->vel.y * deceleration;
    }
  
}

void ReleaseFigures(){
    //TODO revisar los free haciendo debug
    for (int i = 0; i < kNAsteroidsBase; i++)
    {
        free(((base_asteroids + i)->points));
        ((base_asteroids + i)->points) = nullptr;
    }
    
    free(base_asteroids);
    base_asteroids = nullptr;

    for (int i = 0; i < 2; i++)
    {
        free(((base_particulas + i)->points));
        ((base_particulas + i)->points) = nullptr;
    }

    free(base_particulas);
    (base_particulas) = nullptr;


    free((base_shoot.points));
    base_shoot.points = nullptr;

    free((base_ovni.points));
    base_ovni.points= nullptr;

    free(ship.figure.points);
    ship.figure.points = nullptr;

    free(ship.figure.tr_points);
    ship.figure.tr_points = nullptr;

    free(ovni.figure.points);
    ovni.figure.points = nullptr;

    free(ovni.figure.tr_points);
    ovni.figure.tr_points = nullptr;

    for (int i = 0; i < kShootPool; i++)
    {
        free(((shoots + i)->figure.tr_points));
        ((shoots + i)->figure.tr_points) = nullptr;

    }

    free(shoots);
    shoots = nullptr;

    for (int i = 0; i < kAsteroidPool; i++)
    {
        free(((game_asteroids + i)->figure.tr_points));
        ((game_asteroids + i)->figure.tr_points) = nullptr;
    }

    free(game_asteroids);
    game_asteroids = nullptr;

    for (int i = 0; i < kParticulasPool; i++)
    {

        free(((particulas + i)->figure.tr_points));
        ((particulas + i)->figure.tr_points) = nullptr;
    }

    free(particulas);
    particulas = nullptr;

    free(P1);
    P1 = nullptr;
    free(P2);
    P2 = nullptr;

    free(copyright);
    copyright = nullptr;

    for (int i = 0; i < n_players; i++)
    {
        free(((player + i)->score_text));
        ((player + i)->score_text) = nullptr;
    }
    free(player);
    player = nullptr;


    free(circle);
    circle = nullptr;

    free(global_entities);
    global_entities = nullptr;

}

void MoveEntities(TEntities *aux, int mode = 0){
   
    if(mode == 0){
        aux->dir = {cosf(aux->figure.transform.rotate), sinf(aux->figure.transform.rotate)};
    }
    aux->figure.transform.pos = AddVec2(aux->figure.transform.pos, FloatMultVec2(aux->dir, (aux->vel.x * delta)));
}

void AnimationDeadAsteroids(TTransform tr, int n_asteroids_to_spawn, float dead_scale){
    esat::Vec2 new_scale;
    switch ((int)dead_scale)
    {
    case 60:
        new_scale = kBigAsteroid;
        break;
    case 40:
        new_scale = kMidAsteroid;
        break;
    case 25:
        new_scale = kLittleAsteroid;
        break;
    case 10:
        return;
    default:
        break;
    }

    for (int i = 0; i < n_asteroids_to_spawn; i++)
    {
        TEntities *aux_asteroid = AvailableInPool(game_asteroids, kAsteroidPool);
        if (aux_asteroid != nullptr)
        {
            aux_asteroid->figure.transform = tr;
            aux_asteroid->active = true;
            int offset = rand() % 4;
            aux_asteroid->figure.points = (base_asteroids + offset)->points;
            memset(aux_asteroid->figure.tr_points, 0, (12 * sizeof(esat::Vec2)));
            aux_asteroid->figure.vertex = (base_asteroids + offset)->vertex;
            aux_asteroid->figure.transform.scale = new_scale;
            offset = rand()%knVertexCircle;
            aux_asteroid->dir = Vec2Normalize((SubVec2({0.0f, 0.0f}, *(circle + offset))));
            aux_asteroid->figure.transform.rotate = d * offset; 
        }
    }
}

void SpawnParticulas(esat::Vec2 position, int n_p_to_spawn, int mode = 0){
    for (int i = 0; i < n_p_to_spawn; i++)
    {
        TEntities *aux_particula = AvailableInPool(particulas, kParticulasPool);
        if (particulas != nullptr)
        {
            int offset = rand()%knVertexCircle;
            switch (mode)
            {
            case 0:
                (aux_particula)->figure.transform.scale = {0.2f, 0.2f};
                (aux_particula)->figure.transform.rotate = d * offset; 
            
                break;
            case 1:
                (aux_particula)->figure.transform.scale = {(((float)((rand()%500) + 500))/100.0f), 0.2f};
                (aux_particula)->figure.transform.rotate = rand()%100; 
            default:
                break;
            }
            
            (aux_particula)->figure.transform.pos = position;
            (aux_particula)->figure.points = (base_particulas)->points;
            memset(aux_particula->figure.tr_points, 0, (4 * sizeof(esat::Vec2)));
            (aux_particula)->figure.vertex = (base_particulas)->vertex;
            (aux_particula)->dir = Vec2Normalize((SubVec2({0.0f, 0.0f}, *(circle + offset))));
            (aux_particula)->active = true;
            (aux_particula)->respawn_timer = ((float)(rand()%100))/100.0f;
            float aux_speed = (float)((rand()%30) + 10);
            aux_particula->vel = {aux_speed, aux_speed};
        }
    }
}

bool DimensionVector(esat::Vec2 p1_1, esat::Vec2 p1_2, esat::Vec2 p2_1, esat::Vec2 p2_2, float offset_col = 0.0f){
    esat::Vec2 v = SubVec2(p1_1, p1_2);
    esat::Vec2 w = SubVec2(p2_1, p2_2);
    esat::Vec2 independent_term = {p2_1.x - p1_1.x, p2_1.y - p1_1.y};

    esat::Vec3 equation1 = {v.x, v.y, independent_term.x};
    esat::Vec3 equation2 = {w.x, w.y, independent_term.y};
    esat::Vec2 solution = SolveEqMat2(equation1, equation2);
    if(solution.x >= (0.0f - offset_col) && solution.x <= (1.0f + offset_col) && 
        solution.y >= (0.0f - offset_col) && solution.y <= (1.0f + offset_col)){
        return true;
    }

    return false;

}

bool EntityColision(TEntities entity1, TEntities entity2, float offset_col = 0.0f){
    for(int i = 0; i < entity1.figure.vertex; i++){
        for(int j = 0; j < entity2.figure.vertex; j++){
            if(DimensionVector(*(entity1.figure.tr_points + i), *(entity1.figure.tr_points + ((i + 1) % entity1.figure.vertex)), *(entity2.figure.tr_points + j), *(entity2.figure.tr_points + ((j + 1) % entity2.figure.vertex)), offset_col)){
                return true;
            }
        }
    }
    return false;
}

void Inmortallity(TEntities *entity, float segs){
    if(entity->inmortal == true && entity->active == true){
        entity->figure.color.r = 100;
        entity->figure.color.g = 100;
        entity->figure.color.b = 100;
        entity->inmortal_timer += delta;
        if(entity->inmortal_timer > segs){
            entity->figure.color.r = 255;
            entity->figure.color.g = 255;
            entity->figure.color.b = 255;            
            entity->inmortal = false;
            entity->inmortal_timer = 0;   
            bool_hyperspace = false;
        }
    }
}

void ManageSpawnTimer(TEntities *entity, float segs, int mode){

    if(entity == nullptr){
        return;
    }
    switch (mode)
    {
    case 0: 
            if(entity->active == true){
                return;
            }
            entity->respawn_timer += delta;
            if((entity)->respawn_timer >= segs){
                (entity)->respawn_timer = 0.0f;
                (entity)->figure.transform.pos = {400.0f, 300.0f};
                entity->figure.transform.rotate = -M_PI_2;
                (entity)->active = true;
            }
        break;
    case 1:
            if(entity->active == false){ 
                return;
            }
            entity->respawn_timer += delta;
            if((entity)->respawn_timer >= segs){
                (entity)->respawn_timer = 0.0f;
                (entity)->active = false;
            }
        break;
    default:
            printf("caso no contemplado: %d\n", mode);
        break;
    }
}

void ChangePlayer(){
    (player + current_player)->lives--;
    if (multiplayer)
    {
        current_player++;
        if (current_player > 1)
        {
                current_player = 0;
        }
    }
}

void CollideShipAsteroid(TEntities *pool_1, int n_entities1, TEntities *pool_2, int n_entities2, TPlayer *player){
    for(int i = 0; i < n_entities1; i++){
        if((pool_1 + i)->active && (pool_1 + i)->inmortal == false){
            for(int j = 0; j < n_entities2; j++){
                if((pool_2 + j)->active && EntityColision(*(pool_1 + i), *(pool_2 + j))){
                        SpawnParticulas((pool_1 + i)->figure.transform.pos, 3, 1);
                        (pool_1 + i)->active = false;
                        (pool_1 + i)->inmortal = true;
                        ChangePlayer();
                        
                }
            }
        }
    }
}

void CollideOvniShip(TEntities *ov, TEntities *sh){
    if(sh->active && sh->inmortal == false){
        if(ov->active && EntityColision(*sh, *ov)){
            SpawnParticulas((sh)->figure.transform.pos, 3, 1);
            (sh)->active = false;
            (sh)->inmortal = true;
            ChangePlayer();
        }

    }
}

void CollideOvniAsteroids(TEntities *ov, TEntities *as, int n_asteroids){
    if(ov->active){
        for(int i = 0; i < n_asteroids; i++){
            if((as + i)->active && EntityColision(*ov, *(as + i))){
                ov->active = false;
                (as + i)->active = false;
                ov->figure.transform.pos = {-100.0f, (float)(rand() % kWindowHeight)};
                AnimationDeadAsteroids({(as + i)->figure.transform.pos, {0.0f, 0.0f}, kBigAsteroid, (float)(rand() % 100), 0.0f, {}}, 2, (as + i)->figure.transform.scale.x);
                SpawnParticulas((as + i)->figure.transform.pos, 10);
                SpawnParticulas((ov)->figure.transform.pos, 10);
                counter_ovni = 0;
                ovni.vel.x = rand() % 2;
                if (ovni.vel.x == 0.0f){ovni.vel.x = -2.5f;ovni.figure.transform.scale = kLittleOvni;}
                if (ovni.vel.x == 1.0f){ovni.vel.x = 2.5f;ovni.figure.transform.scale = kBigOvni;}
            }
        }
    }
}

void AsteroidScore(TPlayer *player, int asteroid_type){
    switch (asteroid_type)
    {
    case 40:
        player->score += 20;
        break;
    case 25:
        player->score += 50;
        break;
    case 10:
        player->score += 100;
        break;
    case 1:
        player->score += 200;
    case 0:
        player->score += 1000;

    default:
        break;
    }
}

int AsteroidsInScreen(){
    int aux = 0;
    for(int i = 0; i < kAsteroidPool; i++){
        if((game_asteroids + i)->active){
            aux++;
        }
    }
    return aux;
}

void CollideShootAsteroid(TEntities *pool_1, int n_entities1, TEntities *pool_2, int n_entities2){
    for(int i = 0; i < n_entities1; i++){
        if((pool_1 + i)->active){
            for(int j = 0; j < n_entities2; j++){
                if((pool_2 + j)->active && EntityColision(*(pool_1 + i), *(pool_2 + j), 0.5f)){
                        AnimationDeadAsteroids({(pool_1 + i)->figure.transform.pos, {0.0f, 0.0f}, kBigAsteroid, (float)(rand()%100), 0.0f, {}}, 2, (pool_2 + j)->figure.transform.scale.x);
                        SpawnParticulas((pool_1 + i)->figure.transform.pos, 10);
                        AsteroidScore((player + current_player), (pool_2 + j)->figure.transform.scale.x);
                        (pool_1 + i)->active = false;
                        (pool_2 + j)->active = false;


                }
            }
        }
    }
}

void CollideShootOvni(TEntities *bullet, int n_bullet, TEntities *ov){
    for(int i = 0; i < n_bullet - 1; i++){
        if((bullet + i)->active){
            if(ov->active && EntityColision(*ov, *(bullet + i))){
                SpawnParticulas((ov)->figure.transform.pos, 10);
                ov->active = false;
                (bullet + i)->active = false;
                AsteroidScore((player + current_player), 1);
                counter_ovni = 0;
                ov->figure.transform.pos = {-100.0f, (float)(rand() % kWindowHeight)};
                ovni.vel.x = rand() % 2;
                if (ovni.vel.x == 0.0f){ovni.vel.x = -2.5f;ovni.figure.transform.scale = kLittleOvni;}
                if (ovni.vel.x == 1.0f){ovni.vel.x = 2.5f;ovni.figure.transform.scale = kBigOvni;}
            }
        }
    }
}

void CollideShoot_of_Ovni_Ship(TEntities *bullet, TEntities *ship){
    if(bullet->active){
        if(ship->active && EntityColision(*ship, *bullet)){
            ship->active = false;
            SpawnParticulas(ship->figure.transform.pos, 3, 1);
            (ship)->inmortal = true;
            ChangePlayer();
        }
    }
}

void ScreenText(TPlayer *player, float pos_x)
{
    esat::DrawSetTextSize(50.0f);
    esat::DrawSetFillColor(255,255,255);
    sprintf(player->score_text, "%06d", player->score);
    esat::DrawText(pos_x, 45, player->score_text);
    esat::DrawSetTextSize(20.0f);
    esat::DrawText(350, 580, copyright);
    esat::DrawSetTextSize(50.0f);
    if(multiplayer){
        if(current_player == 0){

            esat::DrawText(370, 45, P1);
        }
        if(current_player == 1){
            esat::DrawText(370, 45, P2);

        }
    }

}

void DrawLives(TPlayer *p, float pos_x){
    for(int i = 0; i < p->lives; i++){
        esat::DrawSprite(ship_lives, (30* i) + pos_x, 50);
    }
}

void DrawUi(){
    ScreenText((player + 0),10);
    DrawLives((player + 0),10);

    if(multiplayer){
        ScreenText((player + 1),600);
        DrawLives((player + 1),600);
    }
}

void UpgradeLevel(TPlayer *p){
    if(hardcore == false){
        if(AsteroidsInScreen() == 0){
            if(level < 6){
                level++;
            }
            cont_init_asteroids = 0;
        }
    }
    if(hardcore == true){
        if(AsteroidsInScreen() == 0){
            level++;
            cont_init_asteroids = 0;
        }
    }
}

void PowerUpLive(){
    if((player + current_player)->score > (player + current_player)->n_score_to_up_live){
        (player + current_player)->lives++;
        (player + current_player)->n_score_to_up_live += 10000;
    }
}

void MoveOvni(TEntities *aux){
    aux->figure.transform.pos.x += aux->vel.x;
    counter_movement += delta;

    if(counter_movement >= 3.0f && counter_movement <= 4.5f){
        aux->figure.transform.pos.y += aux->vel.y;
    }
    if(counter_movement >= 10.0f && counter_movement <= 11.0f){
        aux->figure.transform.pos.y -= aux->vel.y;
    
    }
    if(counter_movement >= 15.0f && counter_movement <= 16.5f){
        aux->figure.transform.pos.y += (aux->vel.y - 1.5f);
    }
    if(counter_movement >= 17){
        counter_movement = 0;
    }
}

void SpawnOvni(){
    counter_ovni += delta;

    if(counter_ovni >= 15.0f){
        ovni.active = true;
        counter_bullet_ovni += delta;
        MoveOvni(&ovni);
    }
}
