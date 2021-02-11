apt-get -y update
apt-get -y upgrade
apt-get install -y nginx wget php7.3 php7.3-fpm php7.3-mysql php-common php7.3-cli php7.3-common php7.3-json php7.3-opcache php7.3-readline php-json php-mbstring mariadb-server mariadb-client

echo "         DONE     INSTALLING "
#stargin services
service mysql start
service php7.3-fpm start
service nginx start

#NGINX
chown www-data:www-data /usr/share/nginx/html/ -R
rm -rf /etc/nginx/sites-enabled/default
service nginx reload && service nginx restart
echo "<?php phpinfo(); ?>" > /usr/share/nginx/html/index.php


#Creating Database
mysql < /usr/share/nginx/html/phpmyadmin/sql/create_tables.sql -u root
echo "GRANT ALL PRIVILEGES ON *.* TO 'pma'@'localhost' IDENTIFIED BY 'pmapass';" |mysql -u root
echo "FLUSH PRIVILEGES;" |mysql -u root
echo "CREATE DATABASE wordpress;" |mysql -u root
echo "CREATE USER 'mashad'@'localhost' IDENTIFIED BY 'root';" |mysql -u root
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'mashad'@'localhost';" |mysql -u root
echo "FLUSH PRIVILEGES;" |mysql -u root
echo "CREATE DATABASE app_db;" |mysql -u root
echo "GRANT ALL PRIVILEGES ON *.* TO 'mashad'@'localhost' IDENTIFIED BY 'mashad';" |mysql -u root
echo "FLUSH PRIVILEGES;" |mysql -u root

#phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.2/phpMyAdmin-4.9.2-all-languages.tar.gz
tar -xvf phpMyAdmin-4.9.2-all-languages.tar.gz
mv phpMyAdmin-4.9.2-all-languages /usr/share/nginx/html/phpmyadmin
rm /usr/share/nginx/html/phpmyadmin/config.sample.inc.php
mkdir /usr/share/nginx/html/phpmyadmin/tmp
chmod 777 /usr/share/nginx/html/phpmyadmin/tmp/

#wordpress
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/* /usr/share/nginx/html/
rm -rf wordpress
rm latest.tar.gz
