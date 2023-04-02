var ip;
var appid;
var originX = 0;
var originY = 0;
var isUpdate = true;


var component;
var apps = []

//function createObject(originX, originY, appid)
//{
//    try{
//        var xhr = new XMLHttpRequest;
//        var response
//        xhr.open("GET", "http://192.168.1.165/app/" + appid + "/main.qml");
//        xhr.onreadystatechange = function() {
//            if (xhr.readyState === XMLHttpRequest.DONE) {
//                response = xhr.responseText;

//                if(apps[0])
//                    apps[0].destroy()

//                try{
//                    apps[0] = Qt.createQmlObject(response, application, "firstObject1")
//                    apps[0].launcher(originX, originY);
////                    console.log(apps[0].getAppId())
//                } catch (e) {
//                    console.log("error occurred: " + e.toString());
//                }
//            }
//        };

//        xhr.send(); // begin the request
//    } catch (e) {
//        console.log("error occurred: " + e.toString());
//    }
//}

function createAppObjects() {

    //    component = ("file:///var/www/content/app/ir.roxana.cloudburst/main.qml");

    //    if(component)
    //    component.destroy()

    component = Qt.createComponent("/home/mahdi/CLionProjects/QmlScrcpy/ui/qml/app2.qml")
    //    console.log(component.errorString())
    //    console.log(component.status)

    if (component.status === Component.Ready){
        console.log(originY)
        finishCreation();
        console.log("finishCreation()")
    }else{
        console.log("can not createComponent() " + component.errorString())
        component.statusChanged.connect(finishCreation);
    }
}

function finishCreation() {

    console.log(originY)

    if (component.status === Component.Ready) {
        apps[0] = component.createObject(application, {"x": 100, "y": 100});
        //        var sprite =  component.createObject(application, {"x": 100, "y": 100});
        // if(isUpdate){
        //     apps[0].appUpdate();
        // }else{
            //apps[0].launcher(originX, originY);
        //}

        if (apps[0] === null) {
            // Error Handling
            console.log("Error creating object");
        }
    } else if (component.status === Component.Error) {
        // Error Handling
        console.log("Error loading component:", component.errorString());
    }

}

function exitApp() {

    if(apps[0] !== undefined){
        apps[0].destroy()
        apps[0] = undefined

        console.log("exitApp()")
    }

    component = undefined
}



function runApp(originX, originY, app) {
    var xhr = new XMLHttpRequest
    var response
    xhr.open("GET", server + "/app/setting/Setting.qml")
    xhr.onreadystatechange = function () {
        if (xhr.readyState === XMLHttpRequest.DONE) {
            response = xhr.responseText
            if (app)
                app.destroy()

            try {
                app = Qt.createQmlObject(response, application,
                                         "firstObject")
                app.launcher(originX, originY)
            } catch (e) {
                console.log("error occurred: " + e.toString())
            }
        }
    }
    xhr.send() // begin the request
}





