// Room: /d/huanggong/xig5.c

inherit ROOM;

void create()
{
        set("short", "�乬");
        set("long", @LONG
������ǻʵ۳ͷ����ӵĵط���һ�������ӱ������乬����
�������������ؼ�����֮�ա�����������������춼����ϴ��..
��һ�߽����һ��Ī���ı���Ϯ����ͷ����ǰ��һ��ʹ������
�����ĵ����£��㼸����(cry)�˳�����
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xig6",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}