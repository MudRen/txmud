// /d/huashan/sroad1.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����������󳡱�������С·�����ﵽ������ʯͷ������
���ǳ����ѣ���ǰ��ȴ����һ���޼ʣ��ƺ�û�о�ͷ������û��
��������ȥ�����������������������󳡣�������Ȼ����ʯ·��
LONG
        );
        
        set("exits", ([
                "north" : __DIR__"sroad2",
                "south" : "/d/huashan/tieku",
                //"south" : __DIR__"tieku",
        ]));

        set("outdoors","huashan");

        setup();
}

