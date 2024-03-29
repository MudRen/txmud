// yiguan.c
// by dicky
//此处value为从长安出发的价格。

#include <room.h>
#include <ansi.h>
inherit ROOM;
mapping *paizi=({
([  "name":"成都",      "id":"cd",    "value":150  ]),
([  "name":"明月岛",    "id":"myd",   "value":90   ]),
([  "name":"黑风寨",    "id":"hfz",   "value":90   ]),
([  "name":"华山派",    "id":"hsp",   "value":90   ]),
([  "name":"华阴村",    "id":"hyc",   "value":80   ]),
([  "name":"杭州城",    "id":"hzc",   "value":80   ]),
([  "name":"少林寺",    "id":"sls",   "value":80   ]),
([  "name":"开封府",    "id":"kff",   "value":70   ]),
([  "name":"绯雨阁",    "id":"fyg",   "value":70   ]),
([  "name":"排云寨",    "id":"pyz",   "value":50   ]),
([  "name":"大同府",    "id":"dtf",   "value":50   ]),
([  "name":"天水镇",    "id":"tsz",   "value":50   ]),
([  "name":"奉天城",    "id":"ftc",   "value":50   ]),
([  "name":"汶川镇",    "id":"wcz",   "value":40   ]),
([  "name":"左家村",    "id":"zjc",   "value":40   ]),
([  "name":"踏雪山庄",  "id":"taxue", "value":20   ]),
});
 
string look_paizi();
int do_go(string);

void create()
{
         set("short",HIC"驿馆"NOR);
         set("long", @LONG
这是长安的驿馆，房间很大，弥散着一股牲畜和人夹杂的气味。周围停着
好几辆大车，马儿不停地嘶鸣着。一位老车夫，专门带刚来的新手去江湖各大
门派，他一见你走过来，不敢怠慢，带着笑脸连忙迎上前去。驿馆的中间有根
木柱，柱子上挂着一块牌子（paizi）。
LONG
   );         
         set("exits",([
              "east" : __DIR__"wroad1",
         ]));

         set("item_desc",([
                "paizi" : (: look_paizi :)     
         ]));

         set("objects", ([
                __DIR__"npc/chefu" : 1,
         ]));

         setup();
}

void init()
{
         add_action("do_go", "qu");
}

string look_paizi()
{
         string str=HIW"\n价目表：\n"NOR;
         int i=sizeof(paizi);
         while (i--) {
            str += chinese_number(16-i)+"，";
            str += "去"+paizi[i]["name"];
            str += "("HIW + paizi[i]["id"] + NOR")";
            str += "需"+paizi[i]["value"] + "\n";
         }
         return str;
}
 
void do_move(object ob, int i)
{
        message_vision(YEL"\n$N把钱交给了车夫，车夫领$N上了一辆大车。\n\n"NOR,ob);
        ob->move(__DIR__"npc/che");
}

int do_go(string arg)
{
        object ob=this_player();
        int i=sizeof(paizi);
        if (!arg) return notify_fail("你要去哪里？\n");
        if (ob->is_busy() || ob->is_fighting())
                return notify_fail("你正忙着呢！\n");
        while(i--) {
            if (arg == paizi[i]["id"]){
               switch (player_pay(ob, paizi[i]["value"])) {
                  case 0:
                     return notify_fail("穷光蛋，没钱就别乘车了，自己慢慢走吧！\n");
                  case 2:
                     return notify_fail("有零钱吗？没零钱的话只能自己慢慢走。\n");
               }
               message_vision(HIG"$N在车夫耳边轻声说出所去之地。\n"NOR, ob);

               ob->start_busy(2);
               ob->set_temp("place", arg);
               call_out("do_move", 3, ob, i);
               return 1;
            }
        }
        return notify_fail("你要去哪里？\n");
}

