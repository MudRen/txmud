// Room: /d/huashan/zigongroom.c by pian 2000.8

inherit ROOM;

void create()
{
        set("short", "�����ݺ�Ժ");
        set("long", @LONG
����һ�䲻��ķ��䣬�İ���ء���ǽ����һ��ľ������ͷ
��һ�����С��ϱ���һ�������������������档һλ�ϵ�������
�����ϴ�����
LONG
);

	set("exits",([
	"north" : __DIR__"ciyang",
]));

        set(SAFE_ENV,1);
        
        set("objects", ([ /* sizeof() == 1 */
	__DIR__"npc/shuiyue" : 1,
]));
        
        set("no_magic", 1);
        set("no_spells", 1);
        setup();
}
/*
void init()
{
        add_action("do_leave", "go");
        add_action("do_leave","east");
        add_action("no_quit", "climb");
}


int no_quit()
{
        object me;
        me = this_player();
        if (me->query_temp("zigong")) {
                tell_object(me, "��û��Ǯ����������? û�Ŷ�! \n");
                message_vision("$N�����ˮ�µ����͵�ס�˴���! \n", me);
                return 1;
        }
        return 0;
}

int do_leave(string arg)
{
        object me;
        
        if (arg !="north") return 0;
        
        me = this_player();
        
        if (arg == "north") {
                if (me->query_temp("zigong")) 
                {
                        tell_object(me, "ˮ�µ���Ц�Ŷ���˵���븶����Ǯ��\n");
                        return 1;
                }
                else {
                        me->move(__DIR__"ciyang");
                        return 1;
                }
        }
        
        return 1;
}

*/
