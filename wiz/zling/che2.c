// che3.c
// By dicky

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIY"车厢内"NOR);
        set("long", @LONG
干净舒服的车厢里，整洁的座位上铺着红色的锦缎。车前老车夫正在用力
地赶着马车，马行颠簸，但坐在车内，却并不感觉震荡。透过的车窗你能够欣
赏窗外优美的景色。
LONG
        );
        set("exits/out","/d/changan/yiguan");

        set("no_fight",1);

        setup();
}

void init()
{
        object me=this_player();
        string arg,arg1;
        object place = me->query_temp("place");
        if (!place){
         tell_object(me,YEL"\n车夫拍了拍脑袋说道：你要去那里啊，我可忘了，算了就在这下吧吧。\n\n");
         return;
        }
        switch(place){
            case "ftc":      arg="/d/fengtian/out_fengtian_s";   arg1 ="奉天城"; break;
            case "zjc":      arg="/d/jinghai/zhuque6";           arg1 ="左家村"; break;
            case "myd":      arg="/d/jinghai/moon7";             arg1 ="明月岛"; break;
            case "pyz":      arg="/d/path1/py5";                 arg1 ="排云寨"; break;
            case "dtf":      arg="/d/datong/minju3";             arg1 ="大同府"; break;
            case "hfz":      arg="/d/heifeng/lu10";              arg1 ="黑风寨"; break;
            case "tsz":      arg="/d/tianshui/cross";            arg1 ="天水镇"; break;
            case "hsp":      arg="/d/huashan_zx/guange3";        arg1 ="华山派"; break;
            case "hyc":      arg="/d/huayin/daguchang";          arg1 ="华阴村"; break;
            case "wcz":      arg="/d/wenchuan/fulai";            arg1 ="汶川镇"; break;
            case "sls":      arg="/d/shaolin/tulu1";             arg1 ="少林寺"; break;
            case "kff":      arg="/d/kaifeng/out_kaifeng_n";     arg1 ="开封府"; break;
     case "cd":       arg="/d/chengdu/out_chengdu_n.c";  arg1 ="成都";   break;
            case "hzc":      arg="/d/hangzhou/out_hangzhou_n";   arg1 ="杭州城"; break;
            case "taxue":    arg="/d/houjizhen/shanya";          arg1 ="踏雪山庄"; break;
            case "fyg":      arg="/d/feiyu/shanlu5";             arg1="绯雨阁";  break;
            default: break;
        }
        set("exits/out",arg);
        message_vision(YEL "\n车夫把大车靠在路旁，对你说道："+arg1+"已经到了，快下车（out）吧。\n\n"NOR,me);
}

