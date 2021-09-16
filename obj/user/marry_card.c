// marry_card.c
// by Find.

#include <ansi.h>

inherit ITEM;

protected string master,m_id,couple,c_id,m_date;
protected mapping m_emote = ([
"love" : ([
	"self" : "你又深情的想念你的$t$n了。\n",
	"other" : "你的$m$N又在深情的想你了。\n",
	]),
"hug" : ([
	"self" : "你拥住你的$t$n，深深的一吻，许久。。。许久。。。\n",
	"other" : "你的$m$N拥住你，深深的一吻，许久。。。许久。。。\n",
	]),
]);

protected int max_esum = 12, max_long = 200;
protected void add_self(string r,object me,string emote);
protected void add_other(string self,object me,string emote);
protected void add_finish(string other,object me,string emote,string self);

protected mapping query_emote(string verb)
{
	if(!mapp(m_emote) || undefinedp(m_emote[verb]))
		return 0;

	return m_emote[verb];
}

protected string help()
{
	return "
memote -l             列出当前所有的 emote
memote -d [emote]     删除一个 emote
memote [emote]        如果此 emote 已存在就列出内容
                      如果不存在就编辑加入这个 emote
\n";
}

void set_master(string m,string id,string cn,string cid,string md)
{ master = m; m_id = id;
  couple = cn, c_id = cid; m_date = md; }

void init_emote()
{
	mapping usrmap;
	object env;

	if(!(env = environment())
	|| !userp(env)
	|| (env->query("id") != m_id) )
		return;

	if(!mapp(usrmap = env->query("marry_emote")) || !sizeof(usrmap))
		return;

	m_emote += usrmap;
}

varargs string name(int raw)
{
	string name = ::name(raw);

	if(stringp(master))
		return master + "和" + couple + name;
	return name;
}

protected string query_long()
{
	if(!m_id || !c_id)
		return "无效证书。\n";

	return sprintf("
        %s\n\n\
    今有我朝良善子民:\n\
       %s(%s)\n\
       %s(%s)\n\
两情相悦，符合婚配条件，经本部\n\
批准，结为夫妻。\n\n\n\
         户部签发
     %s%s\n\n",HIY "《证婚书》" NOR,
	master,capitalize(m_id),
	couple,capitalize(c_id),
	MUD_NAME,m_date);
}

void create()
{
	set_name("的证婚书", ({"marry book"}) );

	set("no_get",1);
	set("no_put",1);
	set("no_drop","你的证婚书不能丢弃,只能去官府解除婚约。\n");
	set("no_steal","这是别人的证婚书，你拿来看样子也没什么用处。\n");

	set("long",(: query_long :));

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "本");
		set("material", "paper");
	}
}

void init()
{
	if( m_id
	&& environment()
	&& userp(environment())
	&& (environment()->query("id") == m_id) )
	{
		add_action("do_ce","me");
		add_action("do_ct","mt");
		add_action("do_emote","memote");
	}
}

int do_ce(string arg)
{
	object couple_ob,me;
	string tmpstr1, tmpstr2,strm,stro;
	mapping marry,emote;

	me = environment();
	if(!me || me->query("id") != m_id)
		return 0;

	if( !mapp(marry = me->query("marry")) || !sizeof(marry) )
		return notify_fail("你没有伴侣。\n");

	if((string)me->query("gender") != "男性")
	{
		tmpstr1 = "爱妻";
		tmpstr2 = "夫君";
	}

	else
	{
		tmpstr1 = "夫君";
		tmpstr2 = "爱妻";
	}

	couple_ob = find_player(marry["id"]);

	if( !couple_ob )
		return notify_fail(sprintf("你的%s%s现在无法听见你的声音，或者已经离开游戏了。\n",
			tmpstr2,couple));

	if(!arg)
		return notify_fail("你要对你的伴侣抒发什么样的感情？\n");
	if(!mapp(emote = query_emote(arg)))
		return notify_fail("还没有定义这个 emote。\n");

	strm = replace_string(emote["self"],"$t",tmpstr2);
	strm = replace_string(strm,"$n",couple_ob->name(1));
	stro = replace_string(emote["other"],"$m",tmpstr1);
	stro = replace_string(stro,"$N",me->name(1));

	tell_object(me,sprintf(BWHT YEL "★%s" NOR,strm));
	tell_object(couple_ob,sprintf(BWHT YEL "★%s" NOR,stro));
	return 1;
}

int do_ct(string arg)
{
	object couple_ob,me;
	string tmpstr1, tmpstr2;
	mapping marry;

	me = environment();
	if(!me || me->query("id") != m_id)
		return 0;

	if( !mapp(marry = me->query("marry")) || !sizeof(marry) )
		return notify_fail("你没有伴侣。\n");

	if((string)me->query("gender") != "男性")
	{
		tmpstr1 = "爱妻";
		tmpstr2 = "夫君";
	}

	else
	{
		tmpstr1 = "夫君";
		tmpstr2 = "爱妻";
	}

	couple_ob = find_player(marry["id"]);

	if( !couple_ob )
		return notify_fail(sprintf("你的%s%s现在无法听见你的声音，或者已经离开游戏了。\n",
			tmpstr2,couple));

	if(!arg) arg="...";

	tell_object(me,sprintf(BWHT YEL"你对%s%s说：%s\n"NOR,
		tmpstr2,couple_ob->name(1), arg ));
	tell_object(couple_ob, sprintf(BWHT YEL "%s%s对你说：%s\n"NOR, 
		tmpstr1,me->name(1), arg ));
	return 1;
}

protected string out_all()
{
	string out = "",*key;
	int n;

	n = sizeof(key = keys(m_emote));
	for(int i=0;i<n;i++)
		out += sprintf("EMOTE：\"%s\"
  己方所见：%s
  对方所见：%s\n",key[i],m_emote[key[i]]["self"],m_emote[key[i]]["other"]);
	return out;
}

int delete_emote(string emote)
{
	mapping usrmap;
	object env;

	if(!(env = environment())
	|| !userp(env)
	|| (env->query("id") != m_id) )
		return 0;

	map_delete(m_emote,emote);
	usrmap = env->query("marry_emote");
	if(mapp(usrmap) && !undefinedp(usrmap[emote]))
	{
		map_delete(usrmap,emote);
		env->set("marry_emote",usrmap);
		env->save();
	}

	return 1;
}

// 显示所有的 emote : -l
// 删除 emote: -d
// 无参数显示帮助
// emote: 如存在 显示，不存在就编辑加入(必须是小写字母 3-10)
int do_emote(string arg)
{
	object me = this_player(),coup;
	string emote;
	int n;

	if(!stringp(arg)
	|| (arg == "") )
	{
		write(help());
		return 1;
	}

	if(arg == "-l") // list all
	{
		me->start_more(out_all());
		return 1;
	}

	if(arg[0..1] == "-d")
	{
		object card;

		if(!sscanf(arg,"-d %s",emote))
			return notify_fail("你要删除哪个 emote ？\n");

		if(undefinedp(m_emote[emote]))
			return notify_fail("你没有定义过这个夫妻 emote。\n");
		if(emote == "love" || emote == "hug")
			return notify_fail("这是初始设置的夫妻 emote，不能删除。\n");

		if(!objectp(coup = find_player(c_id)))
			return notify_fail("你的伴侣现在没有在，有事还是一起商量着办吧。\n");

		card = present("marry book",coup);
		if(!card)
		{
			card = new(MARRYCARD_OB);
			card->set_master( couple,
				c_id,
				master,
				m_id,
				m_date);
			if(!card->move(coup))
				return notify_fail("删除失败。\n");
		}
		card->init_emote();
		if(!card->delete_emote(emote))
			return notify_fail("删除失败。\n");
		tell_object(coup,sprintf(HIY"\n你的伴侣将原有的 emote：%s 删除了。\n\n"NOR,emote));

		delete_emote(emote);

		write("ok.\n");
		return 1;
	}

	if(!undefinedp(m_emote[arg]))
	{
		printf("\nEMOTE：\"%s\"
  己方所见：%s
  对方所见：%s\n",arg,m_emote[arg]["self"],m_emote[arg]["other"]);
		return 1;
	}

	if((n=sizeof(arg)) < 3 || n > 10)
		return notify_fail("夫妻 emote 必须是 3 到 10 个英文小写字母。\n");
	for(int i =0; i<n; i++)
		if(arg[i] < 'a' || arg[i] > 'z')
			return notify_fail("夫妻 emote 必须是 3 到 10 个英文小写字母。\n");

	write(sprintf("不存在 %s 这个 emote，是否要编辑加入？(y/n)\n",arg));
	input_to((: add_self :),me,arg);
	return 1;
}

protected void add_self(string r,object me,string emote)
{
	if(!stringp(r) || r=="" || r[0] != 'y')
	{
		write("ok.\n");
		return;
	}

	if(sizeof(m_emote) >= max_esum)
	{
		write("目前设定的 emote 已经很多了，如果在要加入先将不用的删除。\n");
		return;
	}

	if(!find_player(c_id))
	{
		write("你的伴侣现在没有在，有事还是一起商量着办吧。\n");
		return;
	}

	write("请输入作这个 emote 时*自己*看到的信息 (q 退出)：
[$t 你对对方的称谓，$m 对方对你的称谓，$N 你的名字，$n 对方的名字]
------------------------------------------------------------------
");
	input_to((: add_other :),me,emote);
}

protected void add_other(string self,object me,string emote)
{
	if(!stringp(self) || self=="" || self[0] == 'q')
	{
		write("ok.\n");
		return;
	}

	if(strlen(self) > max_long)
	{
		write(sprintf("emote 的长度不要超过 %d 个中文字。\n",max_long/2));
		return;
	}

	write("请输入作这个 emote 时*对方*看到的信息 (q 退出)：
[$t 你对对方的称谓，$m 对方对你的称谓，$N 你的名字，$n 对方的名字]
------------------------------------------------------------------
");
	input_to((: add_finish :),me,emote,self);
}

int add_emote(string self,string other,string emote)
{
	mapping add,usrmap;
	object env;

	if(!(env = environment())
	|| !userp(env)
	|| (env->query("id") != m_id) )
		return 0;

	if(self[<1] != '\n')
		self += "\n";
	if(other[<1] != '\n')
		other += "\n";

	add = ([ "self":self, "other":other]);

	m_emote += ([ emote : add ]);
	usrmap = env->query("marry_emote");
	if(!usrmap)
		usrmap = ([]);
	usrmap += ([ emote : add ]);
	env->set("marry_emote",usrmap);
	env->save();

	return 1;
}

protected void add_finish(string other,object me,string emote,string self)
{
	object coup,card;

	if(!stringp(other) || other=="" || other[0] == 'q')
	{
		write("ok.\n");
		return;
	}

	if(strlen(other) > max_long)
	{
		write(sprintf("emote 的长度不要超过 %d 个中文字。\n",max_long/2));
		return;
	}

	if(!objectp(coup = find_player(c_id)))
	{
		write("你的伴侣现在没有在，有事还是一起商量着办吧。\n");
		return;
	}

	card = present("marry book",coup);
	if(!card)
	{
		card = new(MARRYCARD_OB);
		card->set_master( couple,
			c_id,
			master,
			m_id,
			m_date);
		if(!card->move(coup))
		{
			write("加入 emote 失败。\n");
			return;
		}
	}
	card->init_emote();
	if(!card->add_emote(self,other,emote))
	{
		write("加入 emote 失败。\n");
		return;
	}
	tell_object(coup,sprintf(HIY"\n你的伴侣新加入了一个emote：%s\n\n"NOR,emote));
	add_emote(self,other,emote);

	write(sprintf("\nEMOTE：\"%s\"
  己方所见：%s
  对方所见：%s\n已加入。\n",emote,self,other));
}

void owner_is_killed() { destruct(this_object()); }
