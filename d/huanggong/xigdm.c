// Room: /d/huanggong/xigdm.c

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
���Ѿ�������С·�ľ�ͷ��̧ͷ��ȥ��������¥��д����
������������������ǹ���������޹��ˡ��ſ�վ��һ����ʿ��
���������ӣ�ʱ�̱�������İ�ȫ��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhaig",
  "north" : __DIR__"xig1",
]));
        set("no_clean_up", 0);
        set("outdoors", "huangong");
        setup();
        replace_program(ROOM);
}

