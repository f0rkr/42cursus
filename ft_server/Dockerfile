FROM debian:buster


#Configuring Nginx
ADD src /tmp/src
ADD src/ssl /etc/nginx/ssl
RUN chmod +x /tmp/src/steps.sh
RUN bash /tmp/src/steps.sh
COPY src/config.inc.php /usr/share/nginx/html/phpmyadmin/
COPY src/php.ini /etc/php/7.3/fpm/
COPY src/start.sh /
RUN chmod +x /start.sh
COPY src/default.conf /etc/nginx/conf.d/
CMD sh /tmp/src/start.sh
