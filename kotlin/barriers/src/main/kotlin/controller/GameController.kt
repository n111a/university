package controller

import io.vertx.core.Vertx
import io.vertx.core.json.JsonObject
import io.vertx.ext.web.RoutingContext
import io.vertx.ext.web.templ.freemarker.FreeMarkerTemplateEngine
import roomcontainer.Room
import kotlin.io.println as println

class GameController(vertx: Vertx) {

  private val templateEngine: FreeMarkerTemplateEngine = FreeMarkerTemplateEngine.create(vertx)


  fun homePageHandler(routingContext: RoutingContext) {
    try {
      val session = routingContext.session()
      val playerName = routingContext.request().getParam("name")
      val color = routingContext.request().getParam("color")
      val id = Room.addPlayer(playerName, color)
      if (id == 1) {
        routingContext.response().putHeader("Location", "/playground?first=-1&second=-1&id=1&cur=1").setStatusCode(302).end()
      } else if(id == 2) {
        routingContext.response().putHeader("Location", "/playground?first=-1&second=-1&id=2&cur=1").setStatusCode(302).end()
      }
    } catch (e: Exception) {
      routingContext.next()
    }
  }
  fun handlePlayground(routingContext: RoutingContext){
    val session = routingContext.session()
    val first = routingContext.request().getParam("first").toInt()
    val second = routingContext.request().getParam("second").toInt()
    val id = routingContext.request().getParam("id").toInt()
    val cur = routingContext.request().getParam("cur").toInt()

    if(first!= -1 && second != -1 && Room.currentPlayer == id) {
      if(Room.tableStatus[first] == 0 && Room.tableStatus[second] == 0) {
        Room.tableStatus[first] = id
        Room.tableStatus[second] = id
        Room.currentPlayer = cur
        if(id==1) {
          Room.currentName = Room.player2?.name ?: "1"
        }
        if(id==2) {
          Room.currentName =  Room.player1?.name ?: "2"
        }
        println("Cur: $cur id: $id")
      }
    }
    val jsonObject = JsonObject()
    jsonObject.put("color1", Room.player1!!.color)
    jsonObject.put("color2", Room.player2?.color ?: "#ffffff")
    jsonObject.put("status", Room.tableStatus)
    jsonObject.put("current", Room.currentPlayer)
    jsonObject.put("currentName", Room.currentName)
    jsonObject.put("id", id)


    templateEngine.render(jsonObject, "ftl/playground.ftl") {
      routingContext.response().putHeader("content-type", "text/html").end(it.result())
    }

  }



}

