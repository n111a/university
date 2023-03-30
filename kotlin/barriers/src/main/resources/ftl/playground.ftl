<!DOCTYPE html>
<html lang="ru">
<head>
     <title>Barriers</title>
     <meta charset="UTF-8">
     <meta name="description" content="">
     <meta name="keywords" content="">
     <meta name="author" content="">
     <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
    <meta http-equiv="refresh" content="3">
  <style>
    :root
    {
      --first: ${color1};
      --second: ${color2};
    }
    body
    {
      font-family: sans-serif;
      padding: 0;
      margin: 0;

    }
    .full
    {
      height: 100vh;
    }
    .bg-color
    {
      background: rgb(2,0,36);
      background: linear-gradient(160deg, rgba(2,0,36,1) 0%, rgba(9,9,121,1) 33%, rgba(78,25,117,1) 67%);
      color: #ffffff;
    }
    header
    {
      color: #000000;
      padding: 0;
      margin: 0;
      display: flex;
      align-items: center;
      justify-content: center;
    }
    ul
    {
      text-align: center;
      list-style: none;
    }
    a
    {
      line-height: 1.5;
      text-decoration: none;
      font-size: 50px;

    }
    main
    {
      display: flex;
      flex-direction: column;
      justify-content: center;
      align-items: center;
    }
    footer
    {
      padding: 30px;
      font-size: 30px;
      display: flex;
      flex-direction: column;
      justify-content: center;
      align-items: center;
    }
    table
    {
      border: 2px solid #333;
      border-collapse: collapse;
      background-color: #fff;
    }
    tr
    {
      padding: 0;
      margin: 0;
    }
    td
    {
      box-sizing: border-box;
      margin: 0;
      padding: 0;
      height: 50px;
      width: 50px;
      border: 1px solid #959595;
      z-index: 99;
    }
    #settings
    {
      display: flex;
      flex-direction: column;
      justify-content: center;
      align-items: center;
      text-align: center;
    }
    .marked-1, [data-type = "1"]
    {
      background-color: var(--first);
    }
    .marked-0, [data-type = "2"]
    {
      background-color: var(--second);
    }
    .title
    {
      z-index: 10;
      position: absolute;
      left: 50%;
      top: 40%;
      transform: translateX(-50%) translateY(-50%);
      font-family: "Montserrat";
      text-align: center;
      width: 60%;
    }
    .possible
    {
        -moz-box-shadow:0 0 30px#0a0;
-webkit-box-shadow:0 0 30px #0a0;
box-shadow:0 0 30px #0a0;
    }
    .error
    {
      border: 1px #f00;
        -moz-box-shadow:0 0 30px#f00;
-webkit-box-shadow:0 0 30px #f00;
box-shadow:0 0 30px #f00;
    }
  </style>
</head>
<body>
<main id="game" class="full bg-color">
  <h2> Ход игока <i class="current">${currentName}</i></h2>
<table>
  <#list 0..63 as i>
    <#if i % 8 == 0>
      <tr>
    </#if>
        <td class="kletka" data-type="${status[i]}" data-pos="${i}"></td>
     <#if i % 8 == 7 >
       </tr>
     </#if>
  </#list>
</table>
</main>
<script src="../ftl/jquery-3.5.1.min.js" type="text/javascript"></script>
<script>
    var mas = $(".kletka");
    let params = (new URL(document.location)).searchParams;
    let cur = ${current};
    let id = ${id};
    console.log(cur + " " +id);
    var free = 1;
    var count = 0;
    var flag=1;
    win();
    if(cur == id) {
      for (var i = 0; i < 64; i++) {
        $(mas[i]).click(function () {
          $(".possible").removeClass("possible");
          if (free == 1 && $(this).attr("data-type") == "0") {
            flag = 2;
            free = 0;

            var index = $(this).attr("data-pos");
            if (index > 7 && index < 56 && index % 8 != 0 && (index - 0 + 1) % 8 != 0) {
              if ($(mas[index - 1]).attr("data-type") == "0") {
                $(mas[index - 1]).addClass("possible");
                count++;
              }
              if ($(mas[index - 0 + 1]).attr("data-type") == "0") {
                $(mas[index - 0 + 1]).addClass("possible");
                count++;
              }
              if ($(mas[index - 0 + 8]).attr("data-type") == "0") {
                $(mas[index - 0 + 8]).addClass("possible");
                count++;
              }
              if ($(mas[index - 8]).attr("data-type") == "0") {
                $(mas[index - 8]).addClass("possible");
                count++;
              }
            }
            if (index == 0) {
              if ($(mas[index - 0 + 1]).attr("data-type") == "0") {
                $(mas[index - 0 + 1]).addClass("possible");
                count++;
              }
              if ($(mas[index - 0 + 8]).attr("data-type") == "0") {
                $(mas[index - 0 + 8]).addClass("possible");
                count++;
              }
            }
            if (index == 56) {
              if ($(mas[index - 0 + 1]).attr("data-type") == "0") {
                $(mas[index - 0 + 1]).addClass("possible");
                count++;
              }
              if ($(mas[index - 8]).attr("data-type") == "0") {
                $(mas[index - 8]).addClass("possible");
                count++;
              }
            }
            if (index == 63) {
              if ($(mas[index - 1]).attr("data-type") == "0") {
                $(mas[index - 1]).addClass("possible");
                count++;
              }
              if ($(mas[index - 8]).attr("data-type") == "0") {
                $(mas[index - 8]).addClass("possible");
                count++;
              }
            }
            if (index == 7) {
              if ($(mas[index - 1]).attr("data-type") == "0") {
                $(mas[index - 1]).addClass("possible");
                count++;
              }

              if ($(mas[index - 0 + 8]).attr("data-type") == "0") {
                $(mas[index - 0 + 8]).addClass("possible");
                count++;
              }
            }
            if (index < 7 && index > 0) {
              if ($(mas[index - 1]).attr("data-type") == "0") {
                $(mas[index - 1]).addClass("possible");
                count++;
              }

              if ($(mas[index - 0 + 8]).attr("data-type") == "0") {
                $(mas[index - 0 + 8]).addClass("possible");
                count++;
              }
              if ($(mas[index - 0 + 1]).attr("data-type") == "0") {
                $(mas[index - 0 + 1]).addClass("possible");
                count++;
              }
            }
            if (index < 63 && index > 56) {
              if ($(mas[index - 1]).attr("data-type") == "0") {
                $(mas[index - 1]).addClass("possible");
                count++;
              }

              if ($(mas[index - 8]).attr("data-type") == "0") {
                $(mas[index - 8]).addClass("possible");
                count++;
              }
              if ($(mas[index - 0 + 1]).attr("data-type") == "0") {
                $(mas[index - 0 + 1]).addClass("possible");
                count++;
              }
            }
            if (index % 8 == 0 && index != 0 && index != 56) {
              if ($(mas[index - 8]).attr("data-type") == "0") {
                $(mas[index - 8]).addClass("possible");
                count++;
              }

              if ($(mas[index - 0 + 8]).attr("data-type") == "0") {
                $(mas[index - 0 + 8]).addClass("possible");
                count++;
              }
              if ($(mas[index - 0 + 1]).attr("data-type") == "0") {
                $(mas[index - 0 + 1]).addClass("possible");
                count++;
              }
            }
            if (index % 8 == 7 && index != 7 && index != 63) {
              if ($(mas[index - 8]).attr("data-type") == "0") {
                $(mas[index - 8]).addClass("possible");
                count++;
              }

              if ($(mas[index - 0 + 8]).attr("data-type") == "0") {
                $(mas[index - 0 + 8]).addClass("possible");
                count++;
              }
              if ($(mas[index - 1]).attr("data-type") == "0") {
                $(mas[index - 1]).addClass("possible");
                count++;
              }
            }
            if (count > 0) {
              flag = 1;
              console.log("first: " + $(mas[index]).attr("data-type") + " " + index);
              $(mas[index]).addClass("marked-" + cur % 2);
              $(mas[index]).attr("data-type", (cur - 1) % 2 + 1);
              console.log("first: " + $(mas[index]).attr("data-type") + " " + index);
              var poss = $(".possible");
              for (var k = 0; k < poss.length; k++) {
                $(poss[k]).click(function () {
                  if ($(this).attr("data-type") == "0") {
                    console.log("second: " + $(this).attr("data-type") + " " + $(this).attr("data-pos"));
                    $(this).addClass("marked-" + cur % 2);
                    $(this).attr("data-type", (cur - 1) % 2 + 1);
                    var index2 = $(this).attr("data-pos");
                    console.log("second: " + $(this).attr("data-type") + " " + $(this).attr("data-pos"));
                    for (var k = 0; k < poss.length; k++) {
                      $(poss[k]).removeClass("possible");
                    }
                    count = 0;
                    free = 1;
                    flag++;
                    cur = cur%2+1;
                    let xhr = new XMLHttpRequest();
                    console.log('playground?first='+index+"&second="+index2+"&id="+id+"&cur="+cur);
                    xhr.open('GET', '/playground?first='+index+"&second="+index2+"&id="+id+"&cur="+cur);
                    xhr.send();
                    window.location.replace('/playground?first='+index+"&second="+index2+"&id="+id+"&cur="+cur);
                    win();
                  }
                  return 0;
                });
              }

            } else {
              $(mas[index]).addClass("error");
              $(mas[index]).attr("data-type", 3);
              count = 0;
              free = 1;
            }

          }

          return 0;
        });

      }
    }
function win()
{
    var empty = 0;
    for(var l=0; l<63; l++)
    {
        if(l<56)
            if($(mas[l]).attr("data-type")=="0" && $(mas[l+8]).attr("data-type")=="0")
                empty++;
        if(l%8!=7)
        if($(mas[l]).attr("data-type")=="0" && $(mas[l+1]).attr("data-type")=="0")
                empty++;

        if(empty!=0)
        {
            break;
            return 0;
        }

    }
    if(empty==0)
        alert("Игрок " + (cur%2-0+1) +" выиграл");
}
</script>
</body>
