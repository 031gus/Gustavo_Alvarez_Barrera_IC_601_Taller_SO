#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Run as root, of course. (this might not be necessary, because we have to run the script somehow with root anyway)
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi

file=$1

if [ "${file}X" = "X" ];
then
   echo ">>>Debe indicar el archivo del listado con Nombres de los usuarios que se desean Ingresar<<<"
   exit 1
fi


agregarUsuario()
{
	echo "----> Ingresando usuarios... <----"
	eval username="$1" #$f1 = nombreUsuario
	eval passw="$2" #$f2 = pasword     *Por defecto es el nombre del usuario, pero cambia al iniciar la sesion
	eval USID="$3"	#Se puede dejar en blanco
	eval GID="$4"      #Debe existir en etc/group
	eval Com="$5"  #$f5 = UserIDInfo
	eval homeDirect="$6"  #$f6 = homeDirectory
	eval comandShell="$7"	#$f7 = commandShell
	if grep -q "${username}" /etc/passwd	#evauamos si el usuario ya existe
	then
	    echo "Usuario [${username} ya existe en el grupo..."
	else
	 	if grep -i "${GID}" /etc/group   #evaluamos si existe el grupo
	 	then
	     	 useradd "${username}" -p "${passw}" -u "${USID}" -g "${GID}" -c "${Com}" -d "${homeDirect}" -s "${comandShell}"
		     echo  "$username:$pass" | chpasswd --md5	#hacemos que nos pida la contraseña al ingresar al usuario
		     passwd -e  "${username}"	#hacemos l cambio de contraseña una ves iniciado 
		     if [ $? -eq $SUCCESS ];
		     then
		        echo "---->Usuario [${username}] ha sido agregado <---"
		     fi
	 	else   #si el grupo no existe
	            echo "---->Grupo [${GID}] no existe en /etc/group ----> Usuario [${username}] no agregado..."
	 	fi
	fi
}

#lectura del fichero linea por linea
while IFS=: read -r f1 f2 f3 f4 f5 f6 f7
do

    agregarUsuario "\${f1}" "\${f2}" "\${f3}" "\${f4}" "\${f5}" "\${f6}" "\${f7}"
done < ${file}

exit 0