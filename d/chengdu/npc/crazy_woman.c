// crazy_woman.c
// find.

inherit NPC;

string ask_tangmen(object me);
protected void decide_to_enter(string, object);

void create()
{
	set_name("������", ({ "crazy woman" }) );
	set("gender", "Ů��" );
	set("age", 53);
	set("attitude","peaceful");
	set("long", "����һλ�������ڵķ����ӣ�
�������Ǹ�Ҫ���ġ�\n");
	set("combat_exp", 400);
	set("str", 20);
	set("force", 200);

	set("max_kee",9000);
	set_temp("apply/armor",300);
	set("env/wimpy",60);
	set_auto_recover(1);

	set("inquiry",([
	"����" : "������˵������˵�����У������������������ʡ��������ǡ���������������\n",
	"��������" : (: ask_tangmen :),
	"����" : (: ask_tangmen :),
]));

	set("is_beggar",1);
	set("chat_chance", 8);
	set("chat_msg", ({
		"�����Ӻߺ�����˵�������ˡ�������������Ψ�����ܡ�����������\n",
		"�����Ӻߺ�����˵����˭��֪�����С���������������\n",
	}) );

	setup();

	carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_tangmen(object me)
{
	mapping family;

	if( mapp(family = me->query("family")) )
	{
		if(family["family_name"] == "��������")
			return "��Ϊ���ŵ����Թ����鹡��ư�����Ϊ���Ρ�\n";
		else
			return "��֪��ľ�š����š����ţ����������Ŵ���ȥ��������ز���Ҫ���ˡ�����\n";
	}

	if(me->query("class"))
		return "��֪��ľ�š����š����ţ����������Ŵ���ȥ��������ز���Ҫ���ˡ�����\n";

	if(me->query_temp("been_recommend_to_tangmen"))
		return "���Ǻ���˵�����Ͻ�ȥ��ǧ��𵢸飡";


	if( (me->query("age") > 30)
	|| (me->query("cor") < 25)	// ��ʶ
	|| (me->query("kar") < 25)	// ��Ե
	|| (me->query("int") < 25)	// ����
	|| (me->query_skill("dodge",1) < 30)
	|| (me->query_skill("unarmed",1) < 30) )
		return "��֪��ľ�š����š����ţ����������Ŵ���ȥ��������ز���Ҫ���ˡ�����\n";

	tell_object(me, "������˵���������书�������£������ö�������������ɥ������
            ����Ҫ�����ţ������Ƽ��ˣ������Ƽҹ��������
            �úÿ�������Ҳ��ҽ�����(y/n)��");
	input_to((: decide_to_enter :), me);
	return "�á�\n";
}

protected void decide_to_enter(string str, object me)
{
	object room, map_book;
	string mm;

	if(!me || (environment(me) != environment()) )
		return;

	if( !sizeof(str) || ((str[0] != 'y') && (str[0] != 'Y')) )
	{
		tell_object(me,"�����Ӻٺ�һ����Ц˵������ԭ������������ǲ�ǡ�������\n\n����������е��顣\n\n");
		me->apply_condition("tangdu", 4);
		return;
	}

	if( !(room = find_object("/d/tangmen/shulin")) && !(room = load_object("/d/tangmen/shulin")) )
	{
		tell_object(me, "������˵�������ų��������������ҹ���Ա�����죡��\n");
		return;
	}

	if( !(mm = room->query_my_map()) || !(map_book = new(__DIR__"obj/mp_book")) )
	{
		tell_object(me, "������˵�������ŵ�ͼ���������������ҹ���Ա�����죡��\n");
		return;
	}

	map_book->set_my_map(mm);

	tell_object(me, "\n��������ɫ˵�����ã����д˾����Ҿͳ�ȫ�㣡�����˳ɶ�����һֱ����
                �ߣ�[1;34m������·�������Ϸ����[2;37;0m������û��·�ĵط�ʹ��
                ��ǰ���ʯͷ��[1;34m������һ��(push left ʯͷ)��������
                ����(push right ʯͷ)[2;37;0m���Ϳ��Թ�ȥ�ˡ�
                    �������Ż���һ�����ֵ��Թ���ר�ŵ�������֮�ˣ�
                �Ұ��Թ��ĵ�ͼ���㣬[1;34m���������ͼ������������ɣ�[2;37;0m
                    �˵Ȼ��ܾ�����й©�����ˣ����Ѿ��������˻���
                �Ķ�ҩ��[1;34m����֮������㲻�������ţ�������ȫ������
                ʹ�����[2;37;0m������������\n\n");

	if(!map_book->move(me))
	{
		tell_object(me, "������˵����������ʲôҲ�ò����ˣ�Ϲ���ң�����ǲ�����");
		me->apply_condition("tangdu", 4);
		return;
	}
	else
		tell_object(me,sprintf("�����Ӹ���һ%s%s��\n", map_book->query("unit"),map_book->name()));

	me->set_temp("been_recommend_to_tangmen", 1);
	me->set("decide_enter_tangme_time", time());
	me->apply_condition("enter_tangmen", 1);
}

void die()
{
	object *inv, env;

	if(objectp(env = environment()) && sizeof(inv = filter_array(all_inventory(env), (: userp :))))
	{
		tell_room(env, "\n����������ð��һ�Ƶ��������̡�\n");
		inv->apply_condition("tangdu", 8);
	}
	::die();
}

void unconcious()
{
	object *inv, env;

	if(objectp(env = environment()) && sizeof(inv = filter_array(all_inventory(env), (: userp :))))
	{
		tell_room(env, "\n����������ð��һ�Ƶ��������̡�\n");
		inv->apply_condition("tangdu", 8);
	}
	::unconcious();
}
