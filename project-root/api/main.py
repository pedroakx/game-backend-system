import fastapi
from pydantic import BaseModel
import subprocess

app = fastapi.FastAPI()

class Player(BaseModel):
    player_id: int
    rating: int = 1000

@app.get("/")
def root():
    return {"status": "running"}

@app.post("/queue")
def queue(player: Player):
    try:
        result = subprocess.run(
            ["/app/server/server", str(player.player_id), str(player.rating)],
            capture_output=True,
            text=True
        )
        return {"result": result.stdout.strip()}
    except Exception as e:
        return {"error": str(e)}

