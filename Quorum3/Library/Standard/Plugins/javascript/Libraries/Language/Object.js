var globalStaticHash = 1;

function plugins_quorum_Libraries_Language_Object_(optional) {
    this.me = false;
    this.myHash = 0;
    if(optional === undefined) {
    } else {
        me = optional;
    }
    this.GetHashCode = function (value) {
        return this.myHash;
    };
    
    this.myHash = globalStaticHash;
    globalStaticHash = globalStaticHash + 1;
}

function global_number_converter_(value) {
    var result = value % 1 == 0 ? value.toFixed(1) : value;
    result = result + "";
    result = result.replace("e+", "E");
    result = result.replace("e-", "E-");
    return result;
}

function global_truncate_(value) {
    if(value > 0) {
        return Math.floor(value);
    } else {
        return Math.ceil(value);
    }
}

function global_InstanceOf(variable, name) {
    var value = variable.parentNames_;
    if(variable.prototype != null) {
        value = variable.prototype.parentNames_;
    }
    for	(index = 0; index < value.length; index++) {
        if(value[index] == name) {
            return true;
        }
    }
    return false;
}

function global_parseInteger(text) {
    text = text.trim();
    if(text == null) {
        var error = new quorum_Libraries_Language_Errors_CastError_();
        throw error;
    }
    if(text.length == 0) {
        var error = new quorum_Libraries_Language_Errors_CastError_();
        throw error;
    }
    var index = 0;
    var result = 0;
    var isMinus = false;
    if(text.charAt(index) == '+') {
        index = 1;
    } else if(text.charAt(index) == '-') {
        isMinus = true;
        index = 1;
    }
    for (; index < text.length; index++) {
        var char = text.charCodeAt(index) - 48;
        if(char >= 0 && char < 10) {
            result = result * 10;
            result = result + char;
        } else { /* unlike typical javascript, throw an exception from Quorum */
            var error = new quorum_Libraries_Language_Errors_CastError_();
            throw error;
        }
    }
    if(isMinus) {
        result = result * -1;
    }
    return result;
}

function global_parseNumber(text) {
    text = text.trim();
    if (text == null) {
        var error = new quorum_Libraries_Language_Errors_CastError_();
        throw error;
    }
    if (text.length == 0) {
        var error = new quorum_Libraries_Language_Errors_CastError_();
        throw error;
    }
    if(/^(\-|\+)?([0-9]+(\.[0-9]+)?((e|E)(\-|\+)?[0-9]+)?|Infinity)$/.test(text)) {
      return Number(text);
    } else {
        var error = new quorum_Libraries_Language_Errors_CastError_();
        throw error;
    }
}

function global_CheckCast(from, to) {
    if (from === null || from === undefined)
        return from;
    var names = from.parentNames_;
    for(i = 0; i < names.length; i++) {
        if(names[i] == to) {
            return from;
        }
    }
    var error = new quorum_Libraries_Language_Errors_CastError_();
    throw error;
}

//this function needs work and cross-browser testing to make sure it 
//works as expected everywhere. As of now, exceptions in the JavaScript
//version will have incorrect sometimes.
function global_ErrorCheck(error) {
    names = error.parentNames_;
    if (names == null) {
        if(error instanceof TypeError) {
            return new quorum_Libraries_Language_Errors_UndefinedObjectError_();
        } else {
            return new quorum_Libraries_Language_Errors_Error_();
        }
    } else {
        return error; /*it's already a quorum error*/
    }
}

function global_GetValue_(value, type) {
    if (value == null) {
        if(type == "number" || type == "boolean" || type == "integer") {
            throw "An undefined value was detected with the type " + type + ".";
        } else {
            return null;
        }
    } else {
        return value.GetValue();
    }
}