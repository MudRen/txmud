// Room: /d/huanggong/yujt.c

inherit ROOM;

void create()
{
        set("short", "����ͤ");
        set("long", @LONG
����������԰����ߴ�����������԰�����������۵ס��㲻
������ǰ�Ĺ������򶯣������ĺ����ϲ������ۣ���ֻѼ��
����Ϸˮ���� ��Զ��������ܽ���û��һƬ�Դ��������...��
�·�������쳾֮�⣬�������ɽɫ��Ϊ��һ�塣
LONG        );
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"taihjs",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}