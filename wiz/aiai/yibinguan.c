// /d/changan/yibinguan  仪宾馆


inherit ROOM;

void create()
{
        set("short", "仪宾馆");
        set("long", @LONG
这里就是从皇宫北门旁边的仪宾馆，平时是用来接待贵客的
地方，皇室发布消息的时候也会送到这里。这里有个管皇宫日常
事情的太监，据说他是皇上的亲信。
LONG
        );
       set("exits", ([
                "east"             : "/d/huanggong/beim"
]) );

       set("light_up", 1);
       set(SAFE_ENV, 1);

        set("objects", ([
                __DIR__"item_quest/quester" : 1,
        ]));

        setup();
//        replace_program(ROOM);
}

