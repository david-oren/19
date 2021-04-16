# Libft - 19 2021

Ce tout premier projet a pour objectif de coder en C une librairie de fonctions usuelles que l'on pourra utiliser dans tous les autres projets.

## Partie 1
Recoder un ensemble de fonctions de la libc telles que décrites dans leur man respectif.

| Fonctions       | Description    | Valeur renvoyee |
| ------|-----|-----|
| **ft_memset**  	| Remplit les ***n*** premiers octets  de  la zone de mémoire pointée par  ***s*** avec l'octet ***c***.| Un pointeur sur la zone de mémoire ***s***. 	|
| **ft_bzero** 	| Met à 0 les ***n*** premiers octets du bloc pointé par ***s***. 	| Ne renvoie pas de valeur. 	|
| **ft_memcpy** 	| Copie ***n*** octets depuis la zone mémoire ***src*** vers la zone mémoire ***dest***. Les deux zones ne  doivent pas  se  chevaucher. 	| Renvoie un pointeur sur ***dest***. 	|
| **ft_memccpy** 	| Copie au plus ***n*** octets de la zone mémoire ***src*** vers la  zone  mémoire  ***dest***, s'arrêtant dès qu'elle rencontre le caractère ***c***. 	| Renvoie un pointeur sur le caractère immédiatement après c dans la zone dest, ou NULL si c  n'a pas été trouvé dans les n premiers caractères de src. 	|
| **ft_memmove**	| Copie ***n*** octets de la zone de mémoire ***src***  vers  la  zone  ***dest***. Les  deux  zones  peuvent  se chevaucher. 	| Renvoie un pointeur sur ***dest***. 	|
| **ft_memchr** 	| examine les ***n*** premiers octets de la zone mémoire pointée par ***s*** à la recherche du caractère  ***c***. Le  premier  octet  correspondant à ***c*** (interprété comme un unsigned char) arrête l'operation. 	| Renvoie un pointeur  sur  le  premier octet  correspondant,  ou   ***NULL*** si le caractère n'est pas présent dans la zone de memoire concernée.  	|
| **ft_memcmp** 	| Compare  les ***n*** premiers octets des zones mémoire ***s1*** et ***s2***.  Elle renvoie un entier inférieur, égal,  ou  supérieur  à  zero,  si  ***s1***  est respectivement inférieure, égale ou supérieur à ***s2***. 	| Renvoie un  entier  négatif,  ***nul***  ou positif si les ***n*** premiers octets de ***s1*** sont respectivement inférieurs, égaux ou supérieurs aux ***n*** premiers  octets  de ***s2***. 	|
| **ft_strlen** 	| Calcule la longueur de la  chaîne  de caractères ***s***, sans compter le carèctere ***nul '\0'*** final.	| Renvoie le nombre de caractères dans la chaîne ***s***. 	|
| **ft_isalpha** 	| Vérifie  si  l'on a un caractère alphabétique.	| Valeurs  renvoyées  sont non nulles si le caractère ***c*** entre dans la catégorie testée, et zéro sinon. 	|
| **ft_isdigit** 	| Vérifie si l'on a un chiffre (0 a 9). 	|  Valeurs  renvoyées  sont non nulles si le caractère ***c*** entre dans la catégorie testée, et zéro sinon.	|
| **ft_isalnum** 	| Vérifie si  l'on  a  un  caractère  alphanumérique. 	|  Valeurs  renvoyées  sont non nulles si le caractère ***c*** entre dans la catégorie testée, et zéro sinon. 	|
| **ft_isascii** 	| Vérifie si c est  un  ***unsigned  char***  sur  7  bits, entrant  dans  le  jeu  de  caractères **ASCII**. 	|  Valeurs  renvoyées  sont non nulles si le caractère ***c*** entre dans la catégorie testée, et zéro sinon. 	|
| **ft_isprint** 	|  Vérifie  s'il  s'agit  d'un caractère imprimable, y compris l'espace.	|  Valeurs  renvoyées  sont non nulles si le caractère ***c*** entre dans la catégorie testée, et zéro sinon. 	|
| **ft_toupper** 	|  Convertit la lettre ***c*** en majuscule si c'est pos­sible. |   La valeur renvoyée est celle de la  lettre  convertie,  ou bien ***c*** si la conversion n'etait pas possible.|
| **ft_tolower** 	| Convertit la lettre ***c*** en minuscule si c'est pos­sible.	|  	La valeur renvoyée est celle de la  lettre  convertie,  ou bien ***c*** si la conversion n'etait pas possible.|
| **ft_strchr** 	| Renvoie un pointeur sur  la  première occurence du caractère ***c*** dans la chaîne ***s***. 	|  Renvoient un  pointeur sur  le  caractère  correspondant, ou ***NULL*** si le caractère n'a pas été trouvé.	|
| **ft_strrchr** 	| Renvoie un pointeur sur la dernière occurence du caractère ***c*** dans la chaîne ***s***.	|  Renvoient un  pointeur sur  le  caractère  correspondant, ou ***NULL*** si le caractère n'a pas été trouvé.	|
| **ft_strncmp** 	| Compare les deux chaînes ***s1*** et ***s2***, seulment sur les n premiers caractères de ***s1***. Elle renvoie un entier négati, nul, ou positif, si s1  est espectivement inférieure, égale ou supérieure à ***s2***.	|  Renvoient  un  entier inférieur,  égal  ou supérieur à zero si les n pre­ miers octets de ***s1***   est  respectivement  inférieure,  égale  ou supérieure à ***s2***.	|
| **ft_strlcpy** 	| Copie la chaîne pointée par src, y compris le caractère nul (« \0 ») final dans la chaîne pointée par dest. Les deux chaînes ne doivent pas se chevaucher. La chaîne dest doit être assez grande pour accueillir la copie.	| Renvoient un pointeur sur la chaîne destination ***dest***. 	|
| **ft_strlcat** 	| Ajoute la chaîne src terminée par ***NULL*** à la fin de ***dst***. Il ajoutera au plus la taille - ***strlen*** (***dst***) - ***1 octet***, ***NULL*** terminant le résultat.	|  Renvoient la longueur totale de la chaîne créer cela signifie la longueur initiale de ***dst*** plus la longueur de ***src***. |
| **ft_strnstr** 	|  Localise la première occurrence de la chaîne ***s2*** complétée par un caractère nul dans la chaîne ***s1***, où pas plus de n caractères ne sont cherché.	|  Si s2 est une chaîne vide, ***s1*** est renvoyé. Si ***s2*** ne se trouve nulle part dans ***s1***, la valeur ***NULL*** est renvoyée; sinon, un pointeur sur le premier caractère de la première occurrence de ***s2*** est renvoyé.	|
| **ft_atoi** 	| Convertit le début de la chaîne pointée par ***nptr*** en entier de type ***int***.	|  Un entier résultat de la conversion.	|
| **ft_calloc** 	| Alloue la mémoire nécessaire pour un tableau de ***nmemb*** éléments de ***size*** octets, et renvoie un pointeur vers la mémoire allouée. Cette zone est remplie avec des zéros.	|  Renvoient un pointeur vers la mémoire allouée, qui est correctement alignée pour n'importe quel type intégré. Si elles échouent, elles renvoient NULL. NULL peut également être renvoyé par un appel réussi avec ***nmemb*** ou ***size*** égal à zéro.	|
| **ft_strdup** 	| Renvoie un pointeur sur une nouvelle chaîne de caractères qui est dupliquée depuis ***s***.	|  Renvoie un pointeur sur la chaîne dupliquée. NULL est renvoyé s'il n'y avait pas assez de mémoire et errno contient le code d'erreur.	|
<br>

## Partie 2
Coder un certain nombre de fonctions absentes de la libc ou présentes dans une forme di érente.

| Fonctions       | Description    | Valeur renvoyee |
| ------|-----|-----|
| **ft_substr** | Alloue (avec malloc(3)) et retourne une chaine de caractères issue de la chaine donnée en argument. Cette nouvelle chaine commence à l’index ***start*** et a pour taille maximale ***len*** | Renvoie la nouvelle chaine de caractere ou NULL si l’allocation échoue. |
| **ft_strjoin** | Alloue (avec malloc(3)) et retourne une nouvelle chaine, résultat de la concaténation de ***s1*** et ***s2***. | Renvoie la nouvelle chaine de caractères ou NULL si l’allocation échoue. |
| **ft_strtrim** | Alloue (avec malloc(3)) et retourne une copie de la chaine de caractères donnée en argument, sans les caractères spécifiés dans le set donné en argument au début et à la fin de la chaine de caractères. | Renvoie la chaine de caractères trimmée ou NULL si l’allocation échoue. |
| **ft_split** | Alloue (avec malloc(3)) et retourne un tableau de chaines de caracteres obtenu en séparant ***s*** à l’aide du caractère ***c***, utilisé comme délimiteur. Le tableau doit être terminé par NULL. | Renvoie le tableau de nouvelles chaines de caractères, résultant du découpage ou NULL si l’allocation échoue. |
| **ft_itoa** | Alloue (avec malloc(3)) et retourne une chaine de caractères représentant l’integer reçu en argument. Les nombres négatifs doivent être gérés. | Renvoie la chaine de caractères représentant l’integer ou NULL si l’allocation échoue. |
| **ft_strmapi** | Applique la fonction ***f*** à chaque caractère de la chaine de caractères passée en argument pour créer une nouvelle chaine de caractères (avec malloc(3)) résultant des applications successives de ***f***. | Renvoie la chaine de caractères résultant des applications successives de ***f***. Retourne NULL si l’allocation échoue |
| **ft_putchar_fd** | Écrit le caractère c sur le file descriptor donné. | **-** |
| **ft_putstr_fd** | Écrit la chaine de caractères s sur le file descriptor donné. | **-** |
| **ft_putendl_fd** | Écrit La chaine de caractères s sur le file descriptor donné, suivie d’un retour à la ligne. |**-** |
| **ft_putnbr_fd** | Écrit l’integer n sur le file descriptor donné. |**-** |
<br>

## Partie bonus
Quelques pistes pour aller plus loin, avoir des fonctions de manipulation de liste est très pratique.

| Fonctions       | Description    | Valeur renvoyee |
| ------|-----|-----|
