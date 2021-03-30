
function f(x)
{
    var equation=document.getElementById("equation").value;
    return eval(equation);
}

function roots()
{
    const E=0.0001;
    var equation=document.getElementById("equation").value;
    var a=document.getElementById("a").value;
    var b=document.getElementById("b").value;
    var li=document.createElement("li");

    
    if(f(a)*f(b)<0)
    {
        var itr=1;
        var m= (a * f(b) - b * f(a)) / (f(b) - f(a));
        
        while(Math.abs(f(m))>=0.0001)
        {
            var table = document.getElementById("entries");
            var row = table.insertRow(itr);
            var cell1 = row.insertCell(0);
            var cell2 = row.insertCell(1);
            var cell3 = row.insertCell(2);
            var cell4 = row.insertCell(3);
            var cell5 = row.insertCell(4);
            cell1.innerHTML = itr;
            cell2.innerHTML = a;
            cell3.innerHTML = b;
            cell4.innerHTML = m;
            cell5.innerHTML = f(m);

            if ((f(a) * f(m)) > 0)
            {
                a=m;
            }
            else
            {
                b=m;
            }
            m = (a * f(b) - b * f(a)) / (f(b) - f(a));
            itr += 1;
        }
    }
}