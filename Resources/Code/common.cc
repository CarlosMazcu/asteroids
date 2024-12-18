
#define delta ((esat::Time() - g_last_frame) / 1000.0)



typedef enum
{
    kErrorCode_ok,
    kErrorCode_Invalid_Name = -1,
    kErrorCode_Invalid_Birthday = -2,
    kErrorCode_NotSamePassword = -3,
    kErrorCode_Invalid_Password = -4,
    kErrorCode_Invalid_Country = -5,
    kErrorCode_Invalid_Province = -6,
    kErrorCode_Invalid_Mail = -7,
    kErrorCode_Invalid_NickName = -8,
    kErrorCode_Invalid_Surname = -9,
    kErrorCode_Invalid_g_user = -10,
    kErrorCode_Invalid_g_password = -11,
    kErrorCode_nullptr = -12,
    kErrorCode_FullHighScore = -13,
    
} error_codes;

struct bool_error_codes
{
    bool wrongpassword, wrongname, wrongsurname, wrongnickname, wrongcountry, wrongprovince, wrongbirthday, wrongmail, wrongg_user, wrongg_password;
};

struct TBaseFigures{
    int vertex;
    esat::Vec3 *points;
};

struct TColor{
    unsigned char r, g, b, a;
};

struct TTransform{
    esat::Vec2 pos;
    esat::Vec2 origin;
    esat::Vec2 scale;
    float rotate;
    float origin_rotate;
    esat::Mat3 transform_matrix;
};
struct TFigure{
    TTransform transform;
    TColor color;
    esat::Vec3 *points;
    esat::Vec2 *tr_points;
    int vertex;
};
struct TEntities{
    TFigure figure;
    esat::Vec2 dir;
    esat::Vec2 vel;
    float rotate_vel;
    bool active;
    bool inmortal;
    float inmortal_timer;
    float respawn_timer;
};


struct TFigureInter
{
    esat::Vec2 pos;
    float size;
    float gravity;
    esat::SpriteHandle star;
};

struct THighscore{
    int highscore;
    char *user;
};

struct TPlayer{
    int score;
    char *score_text;
    int lives;
    int n_score_to_up_live;
};


struct TUser
{
    char *name, *nickname, *surname, *password, *repeatpassword, *country, *province, *mail;
    int credits, *birthday, id, score, hight_score;
};

struct WindowSettings
{
    bool welcome, login, signup, ctrls, crdts, game, usr, admin, admin_signup, edit_user_for_admin, game_over;
};


bool debug = false;
bool viewpass = false;
bool check_file_admin_window = true;
bool multiplayer;
bool pause = false;
bool exit_game = false;
bool bool_hyperspace = false;
bool hardcore = false;
bool data_save = false;
bool dont_user = false;

int swap;
int level;
int asteroids_screen;
int user_id_for_admin;
int cont_init_asteroids;
int current_player = 0;
int animation_cont = 3;

float counter_bullet_ovni = 0.0f;
float counter_movement = 0.0f;
float counter_ovni = 0.0f;

/// Chars For Login///
char *g_user, *g_password;

/// Chars for UI///
char *P1, *P2, *copyright, *crt, *not_user;

// variables circunferencia animacion
const int knVertexCircle = 60;
esat::Vec2 *circle;
// d = distancia entre cada vertice de la circunferencia
float d;
//-------------------------------
double g_last_frame = 0.0;
/////////////////////////POOLS/////////////////////////
const int kUserSize = 190;
const int kHighscoreSize = 68;
const int kNAsteroidsBase = 4;
const int kAsteroidPool = 50;
const int kShootPool = 30;
const int kParticulasPool = 200;
const int knOvni = 1;
const int n_players = 2;
const int n_figures = 200;
/////////////////////TIPOS DE ASTEROIDES/////////////////////
const esat::Vec2 kBigAsteroid = {40.0f, 40.0f};
const esat::Vec2 kMidAsteroid = {25.0f, 25.0f};
const esat::Vec2 kLittleAsteroid = {10.0f, 10.0f};
const esat::Vec2 kLittleOvni = {10.0f, 10.0f};
const esat::Vec2 kBigOvni = {25.0f, 25.0f};
/// Asteroides dibujados en el menú de inicio////////////////////////////////////////////////////////
const int knPoints_asteroid1 = 13, knPoints_asteroid2 = 12, knPoints_asteroid3 = 11, knPoints_asteroid4 = 13;
/////////////////////////ENTIDADES/////////////////////////
const int kNEntities = 1 + knOvni + kAsteroidPool + kShootPool + kParticulasPool;
//////////////////////////////////////////////////////////
const unsigned int kWindowWidth = 800;
const unsigned int kWindowHeight = 600;
//////////////////////////////////////////////////////////
FILE *regist, *highscore_file, *save_file;
//TODO SAVE FIILE FALTA DOCUMENTAR

esat::SpriteHandle keys, arrows, spacebar, g_key, up_key, esat_logo, ship_lives, white, logo;

esat::Vec2 *asteroid1_points, *asteroid2_points, *asteroid3_points, *asteroid4_points;

float angle_asteroid1 = 6.28f / knPoints_asteroid1, angle_asteroid2 = 6.28f / knPoints_asteroid2, angle_asteroid3 = 6.28f / knPoints_asteroid3, angle_asteroid4 = angle_asteroid1;


bool_error_codes e_codes;

WindowSettings config;

TUser user, *aux_user;

TPlayer *player;

THighscore aux_hs;

TFigureInter *figures;

TBaseFigures *base_asteroids;
TBaseFigures base_shoot;
TBaseFigures *base_particulas;
TBaseFigures base_ovni;


TEntities *particulas;
TEntities *shoots;
TEntities ship;
TEntities *game_asteroids;
TEntities **global_entities;
TEntities ovni;

esat::Vec2 AddVec2(esat::Vec2 A, esat::Vec2 B){
    return{A.x + B.x, A.y + B.y};
}

esat::Vec2 SubVec2(esat::Vec2 A, esat::Vec2 B){
    return{A.x - B.x, A.y - B.y};
}
esat::Vec2 FloatMultVec2(esat::Vec2 A, float B){
    return{A.x * B, A.y * B};
}

void Edge(esat::Vec2 *pos){/**/
    if(pos->y > 600){ pos->y = 0;} 
    if(pos->y < 0){   pos->y = 600;}
    if(pos->x > 800){ pos->x = 0;}
    if(pos->x < 0){   pos->x = 800;}
}


float Vec2Magnitude(esat::Vec2 v){
    float result = sqrtf (v.x * v.x + v.y * v.y);
    return result;
}

esat::Vec2 Vec2Normalize(esat::Vec2 v){
    float m = Vec2Magnitude(v);
    esat::Vec2 normal = {v.x/m, v.y/m};
    return normal;
}

esat::Vec2 SolveEqMat2(esat::Vec3 first_eq, esat::Vec3 second_ec){
    //kramer method
    esat::Vec2 solve;
    //Calculamos el determinante
    float det = (first_eq.x * second_ec.y) - (first_eq.y * second_ec.x);
    //calculamos del determinte de x y de y con los terminos independientes
    solve.x = (first_eq.z * second_ec.y) - (second_ec.z * first_eq.y);
    solve.y = (first_eq.x * second_ec.z) - (second_ec.x * first_eq.z);
    //solucionamos las incógnitas
    solve.x = solve.x / det;
    solve.y = solve.y / det;

    return solve;
}