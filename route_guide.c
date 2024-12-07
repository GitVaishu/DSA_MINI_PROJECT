#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define YELLOW "\x1b[33m"
#define GREEN "\x1b[32m"
#define CYAN "\x1b[36m"
#define MAGENTA "\x1b[35m"

#define BOLD "\x1b[1m"
#define UNDERLINE "\x1b[4m"
#define ITALIC "\x1b[3m"

#define MAX_STOP_NAME_LEN 100

typedef struct cname
{
  char *loc;
  struct cname *next;
  struct cname *prev;
} cname;

typedef struct Node
{
  char arr[MAX_STOP_NAME_LEN];
  struct Node *next;
} node;

const char *locationNames[] = {
    "Parvati Hill Station",
    "Aga Khan Palace",
    "Fashion Street Deccan",
    "Science Park",
    "Shaniwarwada",
    "Alandi"};

void store(int allroute[6][6]);
void pune(int allroute[6][6], cname ***track);
void prims(int n, int distance[6][6], int userlocs[6], cname ***track);
cname *createsll(cname *head, const char *arr);
cname *reversesll(cname *h1);
void display(cname *h);
node *createNode(const char *location);
void displayLocations(node *head);
void freeLinkedList(cname *head);

int main(void)
{
  int place, ch;
  int allroute[6][6];
  int flag = 0;
  printf(BOLD UNDERLINE RED "\n\t\t\t\t*WELCOME TO JOURNEY-JOY <3*\n" RESET);
  printf(MAGENTA BOLD "\n\n\t\t^_^" RESET);
  printf(CYAN "\tEXPLORE YOUR FAVORITE CITY WITH US\t" RESET);
  printf(MAGENTA BOLD "^_^" RESET);
  printf(CYAN ITALIC "\n\tTravel less and explore more!! Save time and the hazard of searching new places to visit\n" RESET);
  printf(CYAN ITALIC "Whether it's your first time in the city or you're looking to rediscover its hidden gems, we've got you covered!\n" RESET);
  printf(CYAN ITALIC "\tLet JOURNEY-JOY guide you through the best spots to explore & make the most of your moment!\n\n\n" RESET);

  printf(RED "~To immerse in the Vibrance of HERITAGE and YOUTH: PUNE ;)-->ENTER 1\n" RESET);
  printf(BLUE "~To embrace the Spirit of HUSTLE and HARMONY: MUMBAI ;)-->ENTER 2\n" RESET);
  scanf("%d", &place);
  store(allroute);
  cname ***track = (cname ***)malloc(sizeof(cname **) * 6);
  for (int i = 0; i < 6; i++)
  {
    track[i] = (cname **)malloc(sizeof(cname) * 6);
  }

  // Initialize track routes for Pune
  track[0][1] = NULL;
  track[0][1] = createsll(track[0][1], "Sarasbaug");
  track[0][1] = createsll(track[0][1], "Nana Peth");
  track[0][1] = createsll(track[0][1], "Ambedkar Bhavan");
  track[0][1] = createsll(track[0][1], "Pune Station");
  track[0][1] = createsll(track[0][1], "Wadia Bungalow");
  track[0][1] = createsll(track[0][1], "Aga Khan Palace");

  track[0][2] = NULL;
  track[0][2] = createsll(track[0][2], "swargate bus stand");
  track[0][2] = createsll(track[0][2], "MG ROAD");
  track[0][2] = createsll(track[0][2], "Fashion Street Deccan");

  track[0][3] = NULL;
  track[0][3] = createsll(track[0][3], "Dandekar Pul");
  track[0][3] = createsll(track[0][3], "Alka Talkies");
  track[0][3] = createsll(track[0][3], "F.C Raod");
  track[0][3] = createsll(track[0][3], "Khadki Post");
  track[0][3] = createsll(track[0][3], "Dapodi");
  track[0][3] = createsll(track[0][3], "Nashik Phata");
  track[0][3] = createsll(track[0][3], "PCMC");
  track[0][3] = createsll(track[0][3], " Science Park");

  track[0][4] = NULL;
  track[0][4] = createsll(track[0][4], "Dnadekar Pul");
  track[0][4] = createsll(track[0][4], "Sarasbaug");
  track[0][4] = createsll(track[0][4], "Swargate");
  track[0][4] = createsll(track[0][4], "tilak Road ");
  track[0][4] = createsll(track[0][4], "Abhinav Chowk");
  track[0][4] = createsll(track[0][4], "Balgandharva Chowk");
  track[0][4] = createsll(track[0][4], "Shaniwarwada");

  track[0][5] = NULL;
  track[0][5] = createsll(track[0][5], "swargate");
  track[0][5] = createsll(track[0][5], "Pune Station");
  track[0][5] = createsll(track[0][5], "Yerawada");
  track[0][5] = createsll(track[0][5], "Vishrant wadi");
  track[0][5] = createsll(track[0][5], "Charholi");
  track[0][5] = createsll(track[0][5], "Alandi");

  track[1][0] = NULL;
  track[1][0] = reversesll(track[1][0]);

  track[1][2] = NULL;
  track[1][2] = createsll(track[1][2], "aga khan palace");
  track[1][2] = createsll(track[1][2], "Yerwada");
  track[1][2] = createsll(track[1][2], "Camps Corner");
  track[1][2] = createsll(track[1][2], "Shivaji Nagar ");
  track[1][2] = createsll(track[1][2], "Deccan Gymkhana");
  track[1][2] = createsll(track[1][2], "Fashion Street Deccan ");
  track[1][2] = createsll(track[1][2], "NULL");

  track[1][3] = NULL;
  track[1][3] = createsll(track[1][3], "aga khan palace");
  track[1][3] = createsll(track[1][3], "Yerwada");
  track[1][3] = createsll(track[1][3], "Camps Corner");
  track[1][3] = createsll(track[1][3], "Shivaji Nagar ");
  track[1][3] = createsll(track[1][3], "Deccan Gymkhana");
  track[1][3] = createsll(track[1][3], "Khadki");
  track[1][3] = createsll(track[1][3], "PCMC ");
  track[1][3] = createsll(track[1][3], "Science Park");

  track[1][4] = NULL;
  track[1][4] = createsll(track[1][4], "aga khan palace");
  track[1][4] = createsll(track[1][4], "Yerwada");
  track[1][4] = createsll(track[1][4], "Shivaji Nagar");
  track[1][4] = createsll(track[1][4], "Deccan Gymkhana");
  track[1][4] = createsll(track[1][4], "FC ROAD");
  track[1][4] = createsll(track[1][4], "Shaniwarwada");

  track[1][5] = NULL;
  track[1][5] = createsll(track[1][5], "aga khan palace");
  track[1][5] = createsll(track[1][5], "Yerwada");
  track[1][5] = createsll(track[1][5], "RanjanGaon");
  track[1][5] = createsll(track[1][5], "Shivaji Nagar");
  track[1][5] = createsll(track[1][5], "Bhosari");
  track[1][5] = createsll(track[1][5], "Dighi");
  track[1][5] = createsll(track[1][5], "ALandi");

  track[2][0] = NULL;
  track[2][0] = reversesll(track[0][2]);
  track[2][0] = createsll(track[2][0], "NULL");

  track[2][1] = reversesll(track[1][2]);
  track[1][0] = createsll(track[0][4], "NULL");

  track[2][3] = NULL;
  track[2][3] = createsll(track[2][3], "Fashion Street Deccan");
  track[2][3] = createsll(track[2][3], "Shivajinagar ");
  track[2][3] = createsll(track[2][3], "Fergusson College Road");
  track[2][3] = createsll(track[2][3], "Khadki");
  track[2][3] = createsll(track[2][3], "Aundh");
  track[2][3] = createsll(track[2][3], "PCMC");
  track[2][3] = createsll(track[2][3], "Science Park");

  track[2][4] = NULL;
  track[2][4] = createsll(track[2][4], "Fashion Street");
  track[2][4] = createsll(track[2][4], "Shivajinagar");
  track[2][4] = createsll(track[2][4], "FC ROAD");
  track[2][4] = createsll(track[2][4], "Bund Garden");
  track[2][4] = createsll(track[2][4], "Shaniwar wada stand");

  track[2][5] = NULL;
  track[2][5] = createsll(track[2][5], "Fashion Street Deccan");
  track[2][5] = createsll(track[2][5], "Shivajinagar");
  track[2][5] = createsll(track[2][5], "Bhosari Chowk");
  track[2][5] = createsll(track[2][5], "Alandi");

  track[3][0] = NULL;
  track[3][0] = reversesll(track[0][3]);
  track[3][1] = NULL;
  track[3][1] = reversesll(track[1][3]);
  track[3][2] = NULL;
  track[3][2] = reversesll(track[2][3]);

  track[3][4] = NULL;
  track[3][4] = createsll(track[3][4], "Science Park, PCMC");
  track[3][4] = createsll(track[3][4], "PCMC Bus Depot");
  track[3][4] = createsll(track[3][4], "Bhosari");
  track[3][4] = createsll(track[3][4], "Shivajinagar");
  track[3][4] = createsll(track[3][4], "Shaniwarwada");

  track[3][5] = NULL;
  track[3][5] = createsll(track[3][5], "Science Park, PCMC");
  track[3][5] = createsll(track[3][5], "Nigdi");
  track[3][5] = createsll(track[3][5], "Bhosari");
  track[3][5] = createsll(track[3][5], "Pimpri");
  track[3][5] = createsll(track[3][5], " Akurdi");
  track[3][5] = createsll(track[3][5], "Dehu Road ");
  track[3][5] = createsll(track[3][5], "ALandi ");

  track[4][0] = NULL;
  track[4][0] = reversesll(track[0][4]);
  track[4][1] = NULL;
  track[4][1] = reversesll(track[1][4]);
  track[4][2] = NULL;
  track[4][2] = reversesll(track[2][4]);
  track[4][3] = NULL;
  track[4][3] = reversesll(track[3][4]);

  track[4][5] = NULL;
  track[4][5] = createsll(track[4][5], "Shaniwarwada");
  track[4][5] = createsll(track[4][5], "Shivajinagar");
  track[4][5] = createsll(track[4][5], "Swargate");
  track[4][5] = createsll(track[4][5], "Akurdi");
  track[4][5] = createsll(track[4][5], " Bhosari");
  track[4][5] = createsll(track[4][5], "Dehu Road");
  track[4][5] = createsll(track[4][5], "Alandi");

  track[5][0] = NULL;
  track[5][0] = reversesll(track[0][5]);
  track[5][1] = NULL;
  track[5][1] = reversesll(track[1][5]);
  track[5][2] = NULL;
  track[5][2] = reversesll(track[2][5]);
  track[5][3] = NULL;
  track[5][3] = reversesll(track[3][5]);
  track[5][4] = NULL;
  track[5][4] = reversesll(track[4][5]);
  if (place == 1)
  {
    pune(allroute, track);

    printf(GREEN "\nENTER 1 if you want to check if any other user is travelling on the same route\n" RESET);
    printf(GREEN "\nENTER 0 to exit :)\n" RESET);
    scanf("%d", &ch);

    long long int phoneNumber;
    if (ch == 1)
    {

      pune(allroute, track);
      printf(GREEN "Enter your phone number:" RESET);
      scanf("%lld", &phoneNumber);
      printf(GREEN "You can contact User 2 for easy travel: %lld\n" RESET, phoneNumber);
      printf("If you find any common place on the route, do contact the other user to save time, money and make new friends >_<");
    }
    else
    {

      printf(RED BOLD "\nTHANK YOU FOR USING OUR SERVICES <3\n SEE YOU SOON\n" RESET);
    }
  }

  else
  {
    printf(RED BOLD "SORRY, OUR DATABASE IS STILL IN PROGESS :(\nWE WILL UPDATE IT SOON!!\nTHANK YOU <3\n" RESET);
  }

  return 0;
}

void store(int allroute[6][6])
{
  int temp[6][6] = {
      {0, 15, 6, 21, 4, 20},
      {15, 0, 6, 18, 9, 17},
      {6, 6, 0, 19, 4, 26},
      {21, 18, 19, 0, 17, 15},
      {4, 9, 4, 17, 0, 22},
      {20, 17, 26, 15, 22, 0}};

  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      allroute[i][j] = temp[i][j];
    }
  }
}

void pune(int allroute[6][6], cname ***track)
{
  int n;
  printf(MAGENTA "\nLOCATIONS TO EXPLORE:~\n" RESET);
  printf("1.Parvati Hill Station\n 2.Aga Khan Palace\n 3.Fashion Street Deccan\n 4.Science Park\n 5.Shaniwarwada\n 6.Alandi\n\n");
  printf(YELLOW "How many places are you curious to explore amongst these?! >_<\n" RESET);
  scanf("%d", &n);

  int userLocs[n];
  for (int i = 0; i < n; i++)
  {
    printf(BLUE "Enter location ID for the place you want to visit %d:" RESET, i + 1);
    scanf("%d", &userLocs[i]);
  }

  int distance[n][n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      distance[i][j] = allroute[userLocs[i] - 1][userLocs[j] - 1];
    }
  }

  // Print the distance matrix
  printf("\nDistance Matrix for selected locations:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", distance[i][j]);
    }
    printf("\n");
  }

  // Run Prim's Algorithm to determine the MST
  prims(n, distance, userLocs, track);
}

void prims(int n, int distance[6][6], int userlocs[6], cname ***track)
{
  int selected[n];
  int noOfEdges = 0;
  int totalWeight = 0;

  // Arrays to store route details
  int routeStart[n - 1], routeEnd[n - 1], routeDistance[n - 1];

  // Initialize all nodes as unselected
  for (int i = 0; i < n; i++)
  {
    selected[i] = 0;
  }

  // Start with the first node
  selected[0] = 1;

  printf(RED "\nTHE BEST ROUTE FOR YOU IS: :)\n" RESET);

  while (noOfEdges < n - 1)
  {
    int min = 9999;
    int x = 0, y = 0;

    // Find the smallest edge
    for (int i = 0; i < n; i++)
    {
      if (selected[i])
      {
        for (int j = 0; j < n; j++)
        {
          if (!selected[j] && distance[i][j])
          {
            if (min > distance[i][j])
            {
              min = distance[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }

    routeStart[noOfEdges] = x;
    routeEnd[noOfEdges] = y;
    routeDistance[noOfEdges] = min;

    printf("\nRoute %d: (%s -> %s) - Distance: %d KM\n", noOfEdges + 1,
           locationNames[userlocs[x] - 1], locationNames[userlocs[y] - 1], min);
    printf("Detailed Travel Route:\n");
    if (track[userlocs[x] - 1][userlocs[y] - 1] != NULL)
    {
      display(track[userlocs[x] - 1][userlocs[y] - 1]);
    }
    else
    {
      printf("No route found for this pair.\n");
    }
    totalWeight += min;
    selected[y] = 1;
    noOfEdges++;
  }

  // Display the MST routes
}

cname *createsll(cname *head, const char *arr)
{
  cname *temp = (cname *)malloc(sizeof(cname));
  temp->loc = (char *)malloc(strlen(arr) + 1);
  strcpy(temp->loc, arr);
  temp->next = NULL;
  temp->prev = NULL;
  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    cname *temp2 = head;
    while (temp2->next != NULL)
    {
      temp2 = temp2->next;
    }
    temp2->next = temp;
    temp->prev = temp2;
  }
  return head;
}

cname *reversesll(cname *head)
{
  cname *temp = NULL;
  cname *current = head;
  while (current != NULL)
  {
    temp = current;
    current = current->next;
  }
  return temp;
}

void freeLinkedList(cname *head)
{
  cname *current = head;
  cname *nextNode;
  while (current != NULL)
  {
    nextNode = current->next;
    free(current->loc);
    free(current);
    current = nextNode;
  }
}

node *createNode(const char *location)
{
  node *newNode = (node *)malloc(sizeof(node));
  strcpy(newNode->arr, location);
  newNode->next = NULL;
  return newNode;
}

void displayLocations(node *head)
{
  node *current = head;
  while (current != NULL)
  {
    printf("%s\n", current->arr);
    current = current->next;
  }
}
void display(cname *head)
{
  cname *current = head;
  if (current == NULL)
  {
    printf(BLUE " SADLY :( No travel routes are available.\n" RESET);
    return;
  }
  while (current != NULL)
  {
    printf("-> %s ", current->loc);
    current = current->next;
  }
  printf("\n");
}