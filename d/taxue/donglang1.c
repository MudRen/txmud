// donglang1.c
// by dicky

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ�����ȣ��ȶ�����Ž��������ķ羰��ÿ��������ɫ�����Ӽ����
Ҳ�������ߵľ��룬���ɫ�������ߣ��ۻ�ɫ�ĵ�ש�����������棬Ѿ�ߡ�ū
����������ȥ����æ���Լ������飬������һ�㵡�����������˻��Ⱦ��ܵ���
��԰�ˣ��������е��ӵ���Ϣ�ң���������Ů���ӵ���Ϣ�ҡ�
LONG
        );

        set("exits", ([
              "west" : __DIR__"dongting",
              "east" : __DIR__"donglang2",
              "north" : __DIR__"xiuxishi",
              "south" : __DIR__"xiuxishi1",
        ]));
        
        setup();
}

int valid_leave(object me, string dir)
{         
        if ((me->query("gender") =="����") && dir =="south" )
           return notify_fail("�������Ҫ�����ߣ�ȴ�������洫��һ��Ů���ӵļ���������ŵø�æ���˳�����\n");
        if ((me->query("gender") == "Ů��") && dir == "north") 
           return notify_fail("Ů���ӻ��ǲ�Ҫ����ȥ�ĺã�����Ͳ������ż��ˡ�\n");
                
        return ::valid_leave(me, dir);
}

