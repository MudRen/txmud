// Room: /d/huashan/tiezhai.c

inherit ROOM;

void create ()
{
        set("short", "��լ");
    set("long", @LONG
������һ����ȫ���\���ǳɵĴ�լԺ��լ������û��һ�ȴ���
�����޷�Ͷ�䵽���ڣ�ʹ�ù��߷ǳ��谵������Լ���ƺ�������
���µ������������㲻���Ĵ��˸���ս��

LONG
        );

  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"blk_road1",
  "west" : __DIR__"xianshi_tomb",
]) );

  set("light_up", 1);

  setup();
}


