// Room: /d/huanggong/wenhd.c

inherit ROOM;

void create()
{
        set("short", "�Ļ���");
        set("long", @LONG
������ǻ���ÿ�ձ���ʫ��ĵط���һ�������ڷ��ڴ�����
���룬����������ž������������Ľ����������ϰ���һ������
<<���ӱ���>>��������������ض�֮�飬�Ǻ���Ҫ��Ҫ��һ�¡�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"daolu5",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}