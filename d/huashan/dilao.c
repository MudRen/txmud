// Room: /d/huashan/dilao.c

inherit ROOM;

void reset()
{
  ::reset();
  remove_call_out("reset");
  call_out("reset",3600);
}

void create ()
{
        set("short", "����");
    set("long", @LONG
������һ��谵�޹���η����η�������һֻ�޴����򼣬
�������������ʼ����Ŀ���������ÿ��°���
LONG
        );

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"blk_room",
]) );

  set("objects",([
        __DIR__"npc/wugong" : 1,
]));

  set("light_up", 1);

  setup();
}

int valid_leave(object me, string dir)
{
        object ob=present("super wugong",environment(me));
        if ( !ob || !objectp(ob) )
                return ::valid_leave(me,dir);
        if ( living(ob) || !ob->query_temp("unconcious") )
           return notify_fail("�������뿪��ǧ������Ȼ�������ſڡ�\n");
        this_player()->delete_temp("dilao_enter");
    return ::valid_leave(me,dir);
}


