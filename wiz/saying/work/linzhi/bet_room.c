//bet_room.c 林芝村的赌场。
inherit DUCHANG;
void create()
{
        set("short", "银钩赌坊");
        set("long", @LONG
这里是江湖闻名的银钩赌坊，虽然很多人都没见过，但是前
几年有几个无恶不作的独行大盗被人堵住的时候都莫名其妙的死
掉了，而且他们死时都念叨着银钩赌坊四个字。赌场里银子、元
宝碰撞声，人们的叫声绕做一团，弥漫着一种神秘的气氛。
LONG
);
        set("item_desc", ([
                "paizi" : 
"
\n本赌场目前开放押(bet)「大小」,规则如下:\n
三粒骰子点数总和：\n
       四   至 十   为「小」(small)，\n
       十一 至 十八 为「大」(big)，\n
您也可以押全色 (all) 即三粒骰子点数相同。\n
如您押的结果和骰子摇出的结果相同，赌一赔一。\n
如您押全色押中了则一赔八，押100两赢800两！\n\n
本赌场只接受银子为赌注,多少不限。\n",
]));
        set("exits", ([
        "east":__DIR__"lz_sroad3",
]));
        set("objects",([
        __DIR__"npc/judge" : 1,
]));
        set(SAFE_ENV,1);
        setup();
}
