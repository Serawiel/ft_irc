#!/bin/sh
set -e

# Read secrets from Docker secrets files
MYSQL_PASSWORD=$(cat /run/secrets/db_password)
MYSQL_USER=$(cat /run/secrets/credentials)

if [ ! -f /var/www/html/wp-config.php ]; then
    echo "Configuring WordPress..."
    cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php

    sed -i "s/database_name_here/${MYSQL_DATABASE}/" /var/www/html/wp-config.php
    sed -i "s/username_here/${MYSQL_USER}/" /var/www/html/wp-config.php
    sed -i "s/password_here/${MYSQL_PASSWORD}/" /var/www/html/wp-config.php
    sed -i "s/localhost/${WORDPRESS_DB_HOST}/" /var/www/html/wp-config.php

    echo "WordPress configured!"
fi

echo "Starting PHP-FPM..."
exec php-fpm7.4 --nodaemonize