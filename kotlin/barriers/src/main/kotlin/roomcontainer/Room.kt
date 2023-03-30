package roomcontainer

import io.vertx.ext.web.Session

object Room {
  var player1: Player? = null
  var player2: Player? = null
  var currentPlayer = 1
  var currentName = "1"
  val tableStatus = IntArray(64)
  var isRoomEmpty = true

  fun addPlayer(name: String, color:String):Int {
    return when {
        player1 == null -> {
          player1 = Player(name, color)
          currentName = name
          1
        }
        player2 == null -> {
          player2 = Player(name, color)
          2
        }
        else -> 0
    }
  }
}
