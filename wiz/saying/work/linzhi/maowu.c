//maowu.c �����үס�ĵط���
inherit ROOM;
void create()
{
        set("short","Сé��");
        set("long", @LONG
����һ���ƾɵ�Сé�ݣ�����֧��������ݶ���ǽ�ڼ�
͸����������΢���Ĺ�������Կ�������Ķ����ѷŵ����Ҳ�
��������ǽ���Ϲ��ż�ͷҰ��Ұ���ƺ��������ʡ�
LONG
        );
        set("exits", ([
        "west":__DIR__"lz_eroad5",
]));
        set("objects",([
        __DIR__"npc/oldman":1,
]));
        setup();
}
