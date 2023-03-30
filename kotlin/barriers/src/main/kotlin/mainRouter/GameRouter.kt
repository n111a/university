package mainRouter

import controller.GameController
import io.vertx.core.Vertx
import io.vertx.core.http.CookieSameSite
import io.vertx.ext.web.Router
import io.vertx.ext.web.handler.SessionHandler
import io.vertx.ext.web.handler.StaticHandler
import io.vertx.ext.web.sstore.LocalSessionStore

class GameRouter {

    fun getRouter(vertx: Vertx): Router {
        val gameController = GameController(vertx)
        val router = Router.router(vertx)
        val sessionStore = LocalSessionStore.create(vertx)
        val sessionHandler = SessionHandler.create(sessionStore)
        sessionHandler.setCookieSameSite(CookieSameSite.STRICT)

        router.route().handler(sessionHandler)

        router.get("/").handler(gameController::homePageHandler)
        router.get("/").handler(StaticHandler.create().setWebRoot("html").setIndexPage("HomePage.html"))
        router.get("/playground").handler(gameController::handlePlayground)
        router.get("/ftl/*").handler(StaticHandler.create().setWebRoot("ftl"))
        return router
    }
}
