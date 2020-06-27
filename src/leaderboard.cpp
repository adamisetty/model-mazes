#include "mylibrary/leaderboard.h"
#include <mylibrary/player.h>
#include <sqlite_modern_cpp.h>

#include <string>
#include <vector>

namespace traffic_rush {

using std::string;
using std::vector;

// See examples: https://github.com/SqliteModernCpp/sqlite_modern_cpp/tree/dev

LeaderBoard::LeaderBoard(const string& db_path) : db_{db_path} {
  db_ << "CREATE TABLE if not exists leaderboard (\n"
         "  name  TEXT NOT NULL,\n"
         "  score INTEGER NOT NULL\n"
         ");";
}

}