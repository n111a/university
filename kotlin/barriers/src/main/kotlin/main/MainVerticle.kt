package main

import io.vertx.core.AbstractVerticle
import io.vertx.core.Promise
import mainRouter.GameRouter

class MainVerticle : AbstractVerticle() {

    override fun start(startPromise: Promise<Void>) {
        val server = vertx.createHttpServer()
        val router = GameRouter().getRouter(vertx)

        server.requestHandler(router).listen(8888) { http ->
            if (http.succeeded()) {
                startPromise.complete()
                println("HTTP server started on port 8888")
            } else {
                startPromise.fail(http.cause())
            }
        }
    }
}
