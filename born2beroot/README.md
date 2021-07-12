# Born2beRoot

</br>


**Ce tuto vous expliquera dans les grande lignes le projet, il n'a pas pour but d'être exhaustif : faites vos recherches et comprenez toujours ce que vous faites. Bon courage !**


Ce projet a pour but de vous faire découvrir le merveilleux monde de la virtualisation.

Vous allez créer votre première machine en respectant des consignes précises et en
utilisant VirtualBox (ou UTM si VirtualBox ne fonctionne pas sur votre machine). 

Ainsi, à la suite de ce projet, vous serez capable d’installer votre propre système d’exploitation
implémentant des règles strictes.

Lien pour [le pdf de correction](https://github.com/secondfry/school21-checklists/blob/8ccdcbee157c228a87057833cd9d63390fd36c3d/ng_1_born2beroot.pdf).

Pour les manipulations demandées durant la correction, voir la fin du tuto.
</br>

___Mise en place de votre VM___
--------------------------------

*Plus d'infos sur les fichiers systemes sous Linux sur [How To Geek](https://www.howtogeek.com/howto/33552/htg-explains-which-linux-file-system-should-you-choose/) et la mise en place des partitions (page un peu vieille) sur [Developpez.com](https://linux.developpez.com/formation_debian/partitionner.html)*
</br>

* Téléchargez la version stable de [Debian](https://www.debian.org/)

Elle se présente sous la forme d'une image CD : un .iso que l'on va monter par la suite dans notre machine virtuelle.

**Si vous souhaitez faire les bonus** vous pouvez suivre cette installation ci, faites par [hanshazairi](https://github.sre.pub/hanshazairi/42-born2beroot/blob/main/README.md) : [ici](https://www.youtube.com/watch?v=2w-2MX5QrQw)

</br>
  
* Lancez la machine virtuelle (VM) VirtualBox, déjà installée sur les ordinateurs de 42 normalement:

Bouton New/Nouvelle (Ctrl + N) :

Nom de votre VM - 
Folder : dans un endroit où vous pouvez utiliser 8Go.

<blockquote>Si vous êtes à 19 vous allez saturer votre session : vous pouvez travailler de maniere temporaire dans le goinfre mais sachez que celui-ci est souvent vidé, pensez donc à exporter votre VM pour ne pas avoir de mauvaise surprise</blockquote>

Type : Linux - 
Version : Debian 64bits 	

Quantitée de RAM allouée à la machine virtuelle : 1 ou 2Go sont suffisants

Créez un disque dur virtuel maintenant (taille recommandée : 8Go) - VDI (VirtualBox Disk Image) - Dynamically allocated - Vérifiez sa localisation et la taille : 8Go - Creat

Allez dans les settings de votre machine virtuelle

_Onglet STORAGE_ - Controller: IDE : Click sur le petit cd bleu en dessous, dans Attributes cliquer sur le disque bleu a coté d'Optical Drive et monter le .iso de la version de Debian 

_Onglet NETWORK_ -Enable Network Adapter : Bridged Adapter/Acces par pont (chez vous) __OU__ NAT (à 42)

_OK_

</br>

* Lancez votre VM 

</br>

__Installation de Debian__
------------------------------------

*Plus d'infos sur [Debian-handbook](https://debian-handbook.info/browse/fr-FR/stable/sect.installation-steps.html) et 
[Doc.Ubuntu](https://doc.ubuntu-fr.org/lvm) et sur la connection via SSH sur [OpenClassRoom](https://openclassrooms.com/fr/courses/43538-reprenez-le-controle-a-laide-de-linux/41773-la-connexion-securisee-a-distance-avec-ssh)*

</br>

Verifiez que le bon iso est utilisé 

<blockquote>Agrandir la fenetre avec l'onglet Video Memory - Virtual Screen : 300%

Pour vous déplacer dans la VM utilisez TAB ou les flèches, pour afficher le mdp : espace, confirmer : enter </blockquote>

Installation - Langue : comme vous voulez - Pays : Belgique (ou votre localisation) - Clavier : selon le votre (Etats-Unis à 42)

Configurer le réseau - Hostname/Nom de la machine : votrelogin suivi de 42, ex : wil42

Domaine : _rien_

Choisissez le mdp pour la partition root & le confirmer

Nom complet nouvel utilisateur : login - Identifiant pour le compteur utilisateur : login - Mdp du nouvel utilisateur : ce que vous voulez

Partitionner les disques : Assisté - utiliser tout un disque avec LVM chiffré

Selectionnez le disque dur à partitionner (termine par VBOX HARDDISK)

Partitionner /home séparée - OUI

Choisissez une chouette phrase secrète avec des chiffres, des lettres et des signes de ponctuation

Partitionner les disques : 7.5 GB

<blockquote>Vérifier que vous avez bien : Groupe de volumes LVM : un volume logique home, un autre root, un autre swap

Sur votre disque dur : une partition primaire pour le boot et une autre partition logique, chiffrée</blockquote>

Terminez le partitionnement et appliquer les changements - OUI

Le système de base s'installe

Faut-il analyser un autre CD ou DVD ? - NON

Config. l'outil de gestion des paquets : Belgique

Miroir de l'archive Debian : deb.debian.org

Mandataire HTTP/Proxy : *vide*

Etude statistique : NON

Séléction des logiciels : Cocher (touche espace) serveur SSH et utilitaires usuel du système, rien d'autre

Installer le GRUB - Sur le /dev/sda ...

Continuer - La VM se relance

Entrez votre phrase secrete

Login : root - entrer le bon mdp
</br></br>

__SUDO__
-----------------------------------------------

*Plus d'infos sur Sudo sur [Wiki.Debian](https://wiki.debian.org/fr/sudo)*

</br>

**Installation**

Installez Sudo : `apt install sudo`

Vérifiez que Sudo est bien installé : `dpkg -l | grep sudo`

**Ajout d'un utilisateur**

Ajoutez un utilisateur au groupe sudo (cet utilisateur pourra donc utiliser la commande sudo) : `adduser <username> sudo`

Verifiez les utilisateurs du groupe sudo : `getent group sudo`

Relancez la VM avec `reboot` pour que les changements prenent effet

Vérifiez qui bénéficie des droits sudo avec la commande `sudo -v`

**Configuration de Sudo**


<blockquote>Tous les fichiers du répertoire /etc/sudoers.d/ ne finissant pas par ~ ou ne contenant pas un . sont lus et analysés lorsque l'on utilise la commande sudo.

Pour modifier le fonctionnement de la commande sudo, l'administrateur du système ne modifie plus le fichier /etc/sudoers mais positionne des fichiers de personnalisation dans le répertoire /etc/sudoers.d.

Source : [Wiki Ubuntu-fr](https://doc.ubuntu-fr.org/sudoers)</blockquote>

Créez un nouveau fichier pour configurer sudo avec `nano /etc/sudoers.d/<filename>`

Ajoutez les commandes suivantes :

Pour limiter les tentatives d'authentification à 3 dans le cas d'un mdp incorrecte :

```
Defaults        passwd_tries=3
```

Pour ajouter un message d'erreur personnalisé :

```
Defaults        badpass_message="<custom-error-message>"
```

Enregistrer l'activité des sudoers dans un fichier de log spécifique (pensez à bien créer ce fichier par la suite):

```
Defaults        log_host, log_year, logfile="/var/log/sudo/<filename>"
```

Pour archiver toutes les input/output de sudo dans /var/log/sudo/ :

```
Defaults        log_input,log_output
Defaults        iolog_dir="/var/log/sudo"
```
Pour forcer à ce que le sudoers ne puisse pas agir ailleurs qu'en mode console :

```
Defaults        requiretty
```
Pour restreindre les path utilisés par sudo :

```
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```
</br></br>

__Configuration SSH & UFW__
------------------------------------

*Plus d'infos sur l'installation du serveur SSH sur Debian sur [Devconnected](https://devconnected.com/how-to-install-and-enable-ssh-server-on-debian-10/) et
l'installation d'UFW et mise en place du pare-feu sur [Digitalocean](https://www.digitalocean.com/community/tutorials/how-to-set-up-a-firewall-with-ufw-on-ubuntu-20-04-fr#:~:text=Vous%20pouvez%20sp%C3%A9cifier%20des%20plages,ufw%20allow%206000%3A6007%2Ftcp)*

</br>

**Installation et parametrage SSH**

* Lancez une maj des paquets : `apt-get update`

* Vérifiez que le serveur ssh est bien installé : `apt-get install openssh-server`

Configurez dans nano afin que le serveur ssh soit actif uniquement sur le port 4242 : `nano /etc/ssh/sshd_config`

Décommentez (-#) la ligne `#Port 22` et mettre : `Port 4242`

Décommentez (-#) la ligne `#PermitRootLogin prohibit-password` et mettre : `PermitRootLogin no`

Sortez du fichier avec Ctrl + X

<blockquote>Sauvegardez (Ecrire) bien votre fichier nano sinon vos modifications seront perdues</blockquote>

Verifiez le status SSH avec `service ssh status`

Connaitre son IP dans la VM : `ip a` 

Notez dans un coin ce qui se trouve après le premier inet, ainsi que la seconde adresse ip un peu plus loin


Allez dans les settings de votre VM (sur virtualBox) - Advanced - Port Forwarding

Dans le Host IP, mettez la premiere adresse ip, Host Port : 4242

Dans le Guest IP : la seconde adresse ip, Host port : 4242

Ok, Ok

Relancez la VM 

</br>

##**Se connecter du terminal de votre ordi sur votre VM via SSH**


Connectez vous à votre VM via le port 4242 avec `ssh <username>@<ip-adress> -p 4242`

Pour sortir de la session : `logout`

</br>

**Installation du parefeu avec UFW**

Installez ufw : `apt-get install ufw`

Activez le pare-feu : `ufw enable`

Bloquez toutes les connections venant de l'exterieur : `ufw default deny incoming`

Permettez aux applications du serveurs d'avoir accès à l'extérieur :`ufw default allow outgoing`

Configurez le pare-feu pour les connexions entrantes sur le port 4242 : `ufw allow 4242`

Vérifiez que tout est en ordre : `ufw status numbered`

<blockquote>Si une des règles ne vous convient pas : `ufw delete [rule_nbr]`</blockquote>

</br></br>

__Mise en place de la politique de mot de passe forte__
-----------------------------------------------

*Plus d'info sur l'autentification d'utilisateur avec PAM sur [Debian.org](https://www.debian.org/doc/manuals/securing-debian-manual/ch04s11.fr.html) et [Systutorials.com](https://www.systutorials.com/docs/linux/man/5-pwquality.conf/)*

</br>

Installez libpam-pwquality et cracklib-runtime (permet de gerer la complexité des mdp) :

```
apt-get -y install libpam-pwquality cracklib-runtime
```

Modifiez la durée à laquelle les mdp peuvent être changés dans le fichier /etc/login.defs (définit la configuration de la suite shadow password (mots de passe cachés) pour le système.) :

```
nano /etc/login.defs
```

Dans la section Password aging controls indiquer le nombre de jour max au bout duquel le mdp expirera :

`PASS_MAX_DAYS 30`

Et le nombre de jour min entre deux modifications du mdp :

`PASS_MIN_DAYS 2`

Dans le fichier de configuration :

```
nano /etc/pam.d/common-password
```

Sur la ligne `password requisite pam_pwquality.so retry=3` ajouter les instructions suivantes :

`difok=7`    Nombre de caractères du nouveau mot de passe qui ne sont pas présents dans l'ancien, par défaut difok=1

`minlen=10`    Taille minimum du nouveau mot de passe. Cependant un bonus d'un caractère en plus est rajouté si un type de caractères différent de plus est présent dans le mot de passe.

`dcredit=-1`    Si dcredit < 0, dcredit est l'opposé du nombre minimum de chiffres dans le nouveau mot de passe, exemple si dcredit = -5, il faut au moins 5 chiffres dans le mot de passe.

`ucredit=-1`    Si ucredit < 0, ucredit est l'opposé du nombre minimum de lettres majuscules dans le nouveau mot de passe, exemple si ucredit = -4, il faut au moins 4 lettres majuscules dans le mot de passe

`maxrepeat=3`    Si maxrepeat=N, alors un caractère ne pourra pas être présent plus de N fois

`reject_username` Verifie que le nom de l'utilisateur n'est pas contenu dans le mot de passe, si oui le mdp est refusé

`enforce_for_root` Pour que ces restrictions prenent effet aussi sur root

Au final votre ligne ressemblera à :

```password        requisite                       pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root```

Sur la ligne du dessous, apres pam_unix.so rajouter `remember=1` pour garder en mémoire le dernier mot de passe utilisé et pouvoir le comparer lors de la creation d'un nouveau mdp.


Créer un nouvel utilisateur :
--

Créez un nouvel utilisateur : `adduser <username>`

Vérifiez qu'il a bien été créé avec `getent passwd <username>`

Vérifiez le temps de validité des mots de passe grace à `sudo chage -l <username>`

Créer un nouveau groupe :
--

Créez un nouveau groupe nommé `user42`

Ajoutez votre nouveau membre à ce groupe avec `adduser <username> user42`

Verifiez que l'user a bien été ajouté au groupe user 42 avec `getent group user42`

</br></br>

__AppArmor__
--

*Plus d'infos sur AppArmor : [Debian-Handbook](https://debian-handbook.info/browse/fr-FR/stable/sect.apparmor.html) et SELinux : [Debian-Handbook](https://debian-handbook.info/browse/fr-FR/stable/sect.selinux.html)*

Normalement installé par défaut, vous pouvez le télécharger avec `apt install apparmor`

Complètez l'installation avec `apt install apparmor-utils`

Vérifiez que le module apparmor fonctionne avec `/usr/sbin/aa-status` ou `apparmor_status`
</br>

__SCRIPT__
--

*Plus d'infos sur le shell sur [Doc-Ubuntu](https://doc.ubuntu-fr.org/projets/ecole/scripting/initiation_au_shell) et le regex sur [Regexr](https://regexr.com/), allez checker le man pour uname, lscpu, awk ... vous pouvez aussi cat les différents fichiers /proc pour voir ce qui vous interesse dans leur contenu*

Créez un fichier monitoring.sh
```
nano monitoring.sh
```
Exemple de script pour **un terminal en anglais**, si vous êtes en français ou une autre langue certaines termes changeront.

```
#!/bin/bash


MEMTOTAL=$(awk '/MemTotal/ {print $2}' /proc/meminfo) 

MEMAVAIL=$(awk '/MemAvail/ {print $2}' /proc/meminfo)

MEMUSED=$((MEMTOTAL - MEMAVAIL))

LVM=$(lsblk | awk '/root/ {print $6}')


wall << End_Of_Message
	
    #Architecture: `uname -a`

    #CPU physical: `lscpu | awk '/^CPU\(s\)/ {print $2}'`

    #vCPU : `grep -c 'processor' /proc/cpuinfo`

    `echo $MEMUSED $MEMTOTAL | awk '{printf "#Memory Usage: %d/%dMB (%.2f%%)\n", ($1/1024), ($2/1024), ($1/$2)*100}'`

    `df --total | tail -n 1 | awk '{printf "#Disk Usage: %d/%dGb (%d%%)\n", ($3/1024), ($2/1048576), $5}'`

    `awk '{print "#CPU load: "$1"%\n"}' /proc/loadavg*100`

    #Last boot: `who -b | awk '{print $3" "$4}'`

    #LVM use: `if [ "$LVM" = "lvm" ];
    then
      echo "yes"
    else
      echo "no"
    fi`
    
    `awk '$4=="01" {count++} END{printf "#Connexions TCP : %d ESTABLISHED\n", count}' /proc/net/tcp`

    #User log: `who | awk '{print $1}' | uniq | wc -l`

    `ip -br a show $(ip route show default | awk '{print $5}') | sed 's/\/[[:digit:]]\{1,3\}//g' | awk '{printf "#Network: IP %s (%s)\n", $3, $4}'`

    `grep -c 'COMMAND' /var/log/sudo/sudo.log | awk '{printf "#Sudo : %d cmd\n", $1}'`

End_Of_Message
```
</br></br>

Qui va fonctionner ainsi :

MEMTOTAL : recup la memoire totale

MEMAVAIL : recup la memoire non utilisée

MEMUSED : Calcul la memoire utilisée

LVM : Recupere le type de partition de /root/, qui devrait etre lvm


wall << End_Of_Message : envoie le message (tout ce qui suit jusqu'à End_Of_Message) dans la commande wall qui le fera s'afficher sur tous les terminaux actifs 

#Architecture: `uname -a` : recup l'ensemble des infos de votre OS

#CPU physical: `lscpu | awk '/^CPU\(s\)/ {print $2}'` : recup dans lscpu la 2eme colone de la ligne qui commence par CPU(s)

#vCPU : `grep -c 'processor' /proc/cpuinfo` : recup dans cpuinfo l'identifiant du CPU 

`echo $MEMUSED $MEMTOTAL | awk '{printf "#Memory Usage: %d/%dMB (%.2f%%)\n", ($1/1024), ($2/1024), ($1/$2)*100}'` : recup les valeurs de MEMUSED et MEMTOTAL, les convertit en MB ( /1024), en fait un % qui est exprimé en float a 2 decimal pret grace à (%.2f%%)

`df --total | tail -n 1 | awk '{printf "#Disk Usage: %d/%dGb (%d%%)\n", ($3/1024), ($2/1048576), $5}'` : recup dans df --total | la derniere ligne | afficher la memoire utilisee dans la 3eme colonne (/en MB) sur la memoire totale dans la 2eme colonne (/en GB) et le pourcentage total de mem utilisé, dans la 5eme colonne

`awk '{print "#CPU load: "$1"%\n"}' /proc/loadavg` : recup dans /proc/loadavg l'utilisation actuelle du CPU + %

#Last boot: `who -b | awk '{print $3" "$4}'` recup dans who les col. 3 et 4 : la date et l'heure

#LVM use: `if [ "$LVM" = "lvm" ]; 	: Compare votre type de partition(LVM) avec lvm et renvoie oui ou non 
then
echo "yes"
else
echo "no"
fi`

`awk '$4=="01" {count++} END{printf "#Connexions TCP : %d ESTABLISHED\n", count}' /proc/net/tcp`  : recup le nombre de connection TCP en comptant dans la col. 4 du /proc/net/tcp le nb de 01

#User log: `who | awk '{print $1}' | uniq | wc -l` : recup dans who la premiere colonne, une seule fois par utilisateur

`ip -br a show $(ip route show default | awk '{print $5}') | sed 's/\/[[:digit:]]\{1,3\}//g' | awk '{printf "#Network: IP %s (%s)\n", $3, $4}'` : recup l'adresse ipV4 et l'adresse MAC avec ip a | grep link/ether | awk 'print $2'

`grep -c 'COMMAND' /var/log/sudo/<name of the file where you put the activity of sudo> | awk '{printf "#Sudo : %d cmd\n", $1}'` 

End_Of_Message


__CRON__
-----------------------------------------------

*Plus d'info sur la configuration de Cron sur [Fedora-fr.org](https://doc.fedora-fr.org/wiki/CRON_:_Configuration_de_t%C3%A2ches_automatis%C3%A9es#:~:text=La%20configuration%20de%20cron%20se,via%20la%20commande%20crontab%20%2De.)*

</br>

Ouvrez le fichier crontab avec `crontab -e`, choisir Nano

Remplacez la ligne 
```
m h  dom mon dow   command
``` 
par 

```
*/10 * * * * sh /path/to/script
```

Votre script s'activera alors toutes les 10min.

</br>

Tout vérifier : service --status-all

</br>

__Correction__
----
</br>
Comparaison de la signature de votre machine virtuelle et de celle que vous avez soumise : 

```
diff <(echo “string 1”) <(echo “string2”)
```

Vous devez savoir expliquer :

- Comment fonctionne une machine virtuelle et son but

- Votre choix entre CentOs et Debian

- Si vous avez choisis Debian : la difference entre apt et Aptitude et ce qu'est APPArmor

- Si vous avez choisis CentOs : ce qu'est SELinux et DNF

Durant la defense votre script devra tourner et afficher les infos voulues sur vos terminaux.

Connectez vous sur un compte user, autre que root, avec le bon mdp.

Vérifiez que le service UFW tourne : 
```
sudo ufw status verbose OU sudo ufw status numbered
```

Vérifiez que le service SSH tourne aussi :
```
sudo service ssh status
```
Vérifiez le systeme d'exploitation :
```
uname -a 
```

Vérifiez a quel groupes appartient le user : ```groups```

Create a new user : 
```
sudo useradd 
```
List different users : 
```
cut -d: -f1 /etc/passwd
```

How set up rules for passwords : modified file :  
```
nano /etc/login.defs (aging of the passwords)
				
nano /etc/pam.d/common-password (pam : library allows root to authenticate users) (difok : number of char that need to be new ones / dcredit : digit / ucredit : majuscule / maxrepeat : repetition of chars / reject_username )
```

Create a new group : 	
```
sudo groupadd evaluating 

sudo adduser new evaluating 
					
sudo getent group evaluating
```
					
Advantages of password policy
—————————————————————————————————————————————————————————

Check hostname : sudo hostname

Modify hostname and reboot : 
```
				sudo nano /etc/hostname
				sudo nano /etc/hosts
				sudo reboot
```
				
View partitions : 
```
sudo lsblk
```
LVM : disk management tool : physical volume (hardware), volume groups : VM and then can divide again : logical volumes : same as doing partitions to a physical ask but inside VM. LVM : allows you to do these divisions. (Flexible in size)

———————————————————————————————————————————————————————————

UFW : 
```
ufw allow 8080

ufw status numbered

ufw delete [rule_nbr]
```
Warning : you need to delete two rules : the one for income and outgoing
——————————————————————————————————————————————————————————

Check sudo is properly installed : 
```
sudo dpkg -l | grep sudo
```

Assign new user to sudo : 
```
sudo adduser <username> sudo
```

Check : 
```
sudo getent group sudo
```
	
Rules for sudo : authentication : 3 attempts, cannot connect with ssh with sudo, paths used by sudo restricted
	
Verify /var/log/sudo folder exist, has one file : sudoers_activity, has history of commands with sudo. Make command : sudo lsblk, should have been updated.
	
```
nano /etc/sudoers.d/myconfig
```
	
( sudo nano /etc/sudoers.d/myconfig)
	
( sudo nano /var/log/sudo/sudoers_activity)
	
——————————————————————————————————————————————————————————
	
Check SSH is installed : ```sudo ssh -V```
	
What is ssh and value of using it : network protocol, secure way to access a computer over a network. Keys and encrypted communication. Enable to log to the computers through network
	
Config file : 
```
nano /etc/ssh/sshd_config
```
Check ssh uses only the port 4242 : 
```
sudo cat /etc/ssh/sshd_config | grep Port
```
	
Use ssh in order to log in with the created user : 
	
 ip a : take first ip address : 127.0.0.1
	
 sudo passwd <user>
	
ssh <user>@127.0.0.1 -p 4242
	
logout
	
—————————————————————————————————————————————————————————
	
Explain you operation of script by displaying it : 
	
cd (to wherever you put your script)
	
```
	sudo nano ./monitoring.sh
```
Script : 
	
_ Memtotal : récupère la memoire, Memavail : recupere la memoire non utilisée, Bemused : difference
	
_LVM : type partition de root
	
_wall << End_Of_Message : career un message qui s’affiche dans les terminaux actifs
	
_Architecture : recupere informations OS
	
_CPU physical : recupere lscpu 
	
_vCPU : recupere cpuinfo
	
_echo $MEMUSED $ MEMTOTAL … : recupere les valeurs de mémoire, les convertit en MB
	
_df …. : affiche la mémoire utilisée et le pourcentage de memoire 
	
_awk… : recupere l’utilisation CPU
	
_Last boot
	
_LVM use
	
_awk.. : nombre de connections TCP
	
_user log 
	
_ip -br : adresse ipV4
	
_nombre de commandes effectuées par sudo 
	
sudo bash monitoring.sh
	
Cron : Programm that allows users to execute scripts, commands or programs at a date/hour specified in advance or according to a specific cycle.
	
Ensure script runs every 1min / every 10 minutes. Make the script stop running when the server starts up.
	
the pdf will ask to launch the script every minute : 
sudo crontab -e
```	
 * * * * * sh /monitoring/monitoring.sh
```	
comment the line with the ****s to desactivate the launch of the script
	
——————————————————————————————————————————————————————
	
shasum born2beroot 
	
goinfre_born2beroot.vdi 


__Sources__
----
https://www.cyberciti.biz/faq/ubuntu-change-hostname-command/

https://doc.ubuntu-fr.org/useradd

https://debian-handbook.info/browse/fr-FR/stable/sect.apparmor.html

https://www.redhat.com/fr/topics/linux/what-is-selinux

https://doc.ubuntu-fr.org/lvm
