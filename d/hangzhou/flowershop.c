// /d/hangzhou/flowershop.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�߽����ţ��㷢�����Ѿ������ڻ��ĺ��󣬸�ʽ�����Ļ���
�������ţ�һ�������ݵ�Ů�������ڻ����У����ݵĴ�ɫҲ��
�ǲ�������΢Ц��
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"changanw3",
]));

	set("objects",([
	__DIR__"npc/hua_boss" : 1,
]));
        setup();
        replace_program(ROOM);
}

