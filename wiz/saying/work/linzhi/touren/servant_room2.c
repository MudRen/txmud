//servant_room2.c �Ůס����
inherit ROOM;
void create()
{
        set("short","�Ů�޴�");
        set("long", @LONG
������ͷ�˸��Ůס�޵ĵط���������һ��ͨ�̣�Ů���Ǿ�
ס��������ﻹ�������ʰ��Ҳ�����룬�ƺ�Ů����ȷʵϲ
���ɾ����Ա߾�Ȼ����һ����С�Ĳ��������������ǳ�������
LONG
        );
        set("exits", ([
        "east":__DIR__"courtyard",
]));
        setup();
}
