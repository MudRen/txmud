//bank_under.c Ǯׯ�ص���ڡ�
inherit ROOM;
void create()
{
        set("short","�ص����");
        set("long", @LONG
������һ��������ʪ�ĵص������Ե�ǽ���Ϲ��ŵ��ˮ�飬
���ϲ����˽�ӡ���ƺ��������˴������߹���
LONG
        );
        set("exits", ([
        "west":__DIR__"bank_d/entry",
]));
        setup();
}
