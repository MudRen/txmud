// /d/mafeng/top.c
// by Find.

protected int push, pull, unlock, is_enter;

string query_long()
{
	if(!is_enter)
		return "���������ɽ��ɽ������ĿԶ��������Ŀ��⸮������Ŀ�
��կңң������������һ��һ��޴��ɽʯ�����ҵ�ɽ�紵����
ս��վ���ȡ�\n";
	else
		return "���������ɽ��ɽ������ĿԶ��������Ŀ��⸮������Ŀ�
��կңң���������ҵ�ɽ�紵����ս��վ���ȡ�������һ�����
��ʯͷ���������ǳ��ر�\n";
}

mixed query_desc_shitou()
{
	if(!is_enter)
		return 0;

	if(!push)
		return "����һ�����ʯͷ���ӹ⻬����������񾭳�������(push)����\n";
	else
		return "����һ��⻬�Ĵ���ʯͷ��\n";
}

mixed query_desc_tieban()
{
	if(!is_enter || !push)
		return 0;

	if(unlock)
		return "����һ����صĴ����壬������һ��������(pull)���İ��֡�\n";
	else
		return "����һ����صĴ����壬������һ��������(pull)���İ��֣������ϻ�����һ�Ѵ�����\n";
}

void set_is_enter(int n)
{
	object ob = previous_object();

	if(!ob)
		return;

	if(!in_same_dir(file_name(ob), __FILE__))
		return;

	if(n > 0)
	{
		is_enter = 1;
		return;
	}

	if( (n <= 0) && (is_enter > 0) )
	{
		if(this_object()->query("exits/down"))
		{
			tell_object(this_object(), "�����чRһ��������������ס�����µĳ��ڡ�\n");
			this_object()->delete("exits/down");
		}

		is_enter = 0; unlock = 0; push = 0; pull = 0;
	}
}

void init()
{
	add_action("do_push", "push");
	add_action("do_pull", "pull");
	add_action("do_unlock", "unlock");
}

int do_push(string arg)
{
	if(!is_enter)
		return 0;

	if(arg != "ʯͷ")
		return notify_fail("��Ҫ��ʲô��\n");

	if(push)
		return notify_fail("����ʯͷ�Ѿ����Ƶ�һ���ˡ�\n");

	message_vision("$N�þ�ȫ������ʹ������һ��ʯͷ��ʯͷ�����Ļ���һ�ߣ�¶����һ�顺���塻��\n", this_player());

	push = 1;

	return 1;
}

protected void close_down()
{
	object room;

	if(!this_object()->query("exits/down"))
		return;

	tell_room(__FILE__, "�����¡һ�����˻�ȥ����ס�����µĳ��ڡ�\n");
	this_object()->delete("exits/down");

	if(!objectp(room = find_object(__DIR__"down1")) && !objectp(room = load_object(__DIR__"down1")))
		return;

	if(room->query("exits/up"))
	{
		tell_object(room, "����������¡һ��������������ס�����ϵĳ��ڡ�\n");
		room->delete("exits/up");
	}
}

int do_pull(string arg)
{
	object room;

	if(!is_enter || !push)
		return 0;

	if(arg != "����")
		return notify_fail("��Ҫ��ʲô������\n");

	if(!unlock)
		return notify_fail("���屻�������ţ�������(unlock)���������ġ�\n");

	if(this_object()->query("exits/down"))
		return notify_fail("�����Ѿ��������ˡ�\n");

	if(!objectp(room = find_object(__DIR__"down1")) && !objectp(room = load_object(__DIR__"down1")))
		return notify_fail("����������һ�����壬���ʲôҲû������\n");

	message_vision("$N����������������¶����һ�����µĳ��ڡ�\n", this_player());

	this_object()->set("exits/down", __DIR__"down1");

	if(!room->query("exits/up"))
	{
		tell_object(room, "��������屻������¶����һ�����ڡ�\n");
		room->set("exits/up", __FILE__);
	}

	call_out("close_down", 15);
	return 1;
}

int do_unlock()
{
	object key, me = this_player();

	if(!is_enter || !push)
		return 0;

	if(unlock)
	{
		write("�����ϵĴ����Ѿ������ˡ�\n");
		return 1;
	}

	if(!objectp(key = present("red copper key", me))
	|| (base_name(key) != __DIR__"npc/obj/key")
#ifdef WIZARD_FLAG
	|| (key->query_wiz_flag() && !wizardp(me))
#endif
	)
	{
		write("������û���������Կ�ף�û�����������\n");
		return 1;
	}

	message_vision(sprintf("$N�ó������%s��������ͱ�˼��£��ǵ�һ���������ˡ�\n",
		key->name()), me);

	destruct(key);

	unlock = 1;

	return 1;
}
