/*
 *  Project:    moba-common
 *
 *  Copyright (C) 2016 Stefan Paproth <pappi-@gmx.de>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/agpl.txt>.
 *
 */

#include "msgtimerhandler.h"

namespace moba {

    void MsgTimerHandler::sendSetGlobalTimer(const std::string &curModelTime, unsigned int intervall, unsigned int multiplicator) {
        JsonObjectPtr obj(new JsonObject());
        (*obj)["curModelTime" ] = toJsonStringPtr(curModelTime);
        (*obj)["intervall"    ] = toJsonNumberPtr(intervall);
        (*obj)["multiplicator"] = toJsonNumberPtr(multiplicator);
        msgep->sendMsg(Message(Message::MT_SET_GLOBAL_TIMER, obj));
    }

    void MsgTimerHandler::sendSetColorTheme(
        const std::string &dimTime, const std::string &brightTime, JsonThreeState::ThreeState condition
    ) {
        JsonObjectPtr obj(new JsonObject());
        (*obj)["dimTime"   ] = toJsonStringPtr(dimTime);
        (*obj)["brightTime"] = toJsonStringPtr(brightTime);
        (*obj)["condition" ] = toJsonThreeStatePtr(condition);
        msgep->sendMsg(Message(Message::MT_SET_COLOR_THEME, obj));
    }
}