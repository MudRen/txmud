// Room: /d/huanggong/yanhg.c

inherit ROOM;

void create()
{
        set("short", "�ӻԸ�");
        set("long", @LONG
һ�����ӻԸ�㱻�������������Ⱦ�����ܶ�������������
������ϸ���������񶰣����ֳ�һ�ɽ�̻Իͣ�������ΰ������
����ׯ���Ƚ��ķ��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yuhy",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}