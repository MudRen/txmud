// Room: /d/huanggong/ningsg.c

inherit ROOM;

void create()
{
        set("short", "���ٹ�");
        set("long", @LONG
�����ǹ�������Ϊ���������ٵĵط����������Ĵ�
һ�Իƽ����ĳ����ƣ������ķ�������ƻ�ͨ����������
һ����Ⱦ��˵�����ﾭ�����˴�ɨ��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huangjd",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

