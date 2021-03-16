//forward declarations to prevent circular dependencies
struct Item;
struct Inventory;
enum MovementResult;


//AI behaviour functions can operate on an item and/or an inventory
//it will return a movement result to tell the caller whether the player is allowed to move
typedef enum MovementResult (*AiBehaviour)(struct Inventory* inventory, struct Item* item);

AiBehaviour textToBehaviour(const char* aiText);